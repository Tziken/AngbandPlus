#undef cquest
#define cquest (quest[QUEST_INVASION])

bool quest_invasion_gen_hook(int q_idx)
{
	int x, y;
        int xstart = 2;
        int ystart = 2;

        if (p_ptr->inside_quest != QUEST_INVASION) return FALSE;

	/* Start with perm walls */
	for (y = 0; y < cur_hgt; y++)
	{
		for (x = 0; x < cur_wid; x++)
		{
			cave[y][x].feat = FEAT_PERM_SOLID; 
		}
	}
        dun_level = quest[p_ptr->inside_quest].level;

	/* Set the correct monster hook */
        set_mon_num_hook();

	/* Prepare allocation table */
	get_mon_num_prep();

        init_flags = INIT_CREATE_DUNGEON;
        process_dungeon_file_full = TRUE;
        process_dungeon_file("maeglin.map", &ystart, &xstart, cur_hgt, cur_wid, TRUE);
        process_dungeon_file_full = FALSE;

        for (x = 3; x < xstart; x++)
        for (y = 3; y < ystart; y++)
        {
                if (cave[y][x].feat == FEAT_MARKER)
                {
                        cquest.data[0] = y;
                        cquest.data[1] = x;
                        py = y;
                        px = x;
                        cave_set_feat(py, px, FEAT_LESS);
                }
        }

        return TRUE;
}
bool quest_invasion_ai_hook(int m_idx)
{
        monster_type *m_ptr = &m_list[m_idx];

        if (p_ptr->inside_quest != QUEST_INVASION) return FALSE;

        /* Ugly but thats better than a call to test_monster_name which is SLOW */
        if (m_ptr->r_idx == 825)
        {
                /* Oups he fleed */
                if ((m_ptr->fy == cquest.data[0]) || (m_ptr->fx == cquest.data[1]))
                {
                        delete_monster_idx(m_idx);

                        cmsg_print(TERM_YELLOW, "Maeglin found the way to Gondolin, all hope is lost now!");
                        cquest.status = QUEST_STATUS_FAILED;
                        return (FALSE);
                }

                /* Attack or flee ?*/
                if (distance(m_ptr->fy, m_ptr->fx, py, px) <= 2)
                {
                        return (FALSE);
                }
                else
                {
                        hack_y2 = cquest.data[0];
                        hack_x2 = cquest.data[1];
                        return (TRUE);
                }
        }

        return (FALSE);
}
bool quest_invasion_plevel_hook(int q_idx)
{
        bool old_quick_messages = quick_messages;

        if (cquest.status != QUEST_STATUS_UNTAKEN) return (FALSE);

        if (p_ptr->lev < 45) return (FALSE);

        /* Ok give the quest */
        quick_messages = FALSE;
        cmsg_print(TERM_YELLOW, "A Dragonrider jumps out of the between in front of you! And says:");
        cmsg_print(TERM_YELLOW, "'Hi noble hero, I am L'ron rider of the bronze Tarath, Turgon king of Gondolin sent me.'");
        cmsg_print(TERM_YELLOW, "'Gondolin is being invaded, he needs your help now or everything will be lost.'");
        cmsg_print(TERM_YELLOW, "'I will bring you to Gondolin, but we need to go now.'");
        if (!get_check("Will you come?"))
        {
                cmsg_print(TERM_YELLOW, "'Turgon overestimated you ... Now Gondolin will fall.'");
                cmsg_print(TERM_YELLOW, "'I will return alone and die there. May you be doomed!'");

                cquest.status = QUEST_STATUS_FAILED;

                quick_messages = old_quick_messages;

                del_hook(HOOK_PLAYER_LEVEL, quest_invasion_plevel_hook);
                process_hooks_restart = TRUE;
                return (FALSE);
        }
        if (p_ptr->prace == RACE_DRAGONRIDDER)
        {
                cmsg_print(TERM_YELLOW, "'You made the right decision, Tarath will show your dragon the way!'");
        }
        else
        {
                cmsg_print(TERM_YELLOW, "'You made the right decision, quickly jump on Tarath!'");
        }
        cmsg_print(TERM_YELLOW, "'Here we are, Gondolin, you must talk to Turgon now.'");

        p_ptr->wild_mode = FALSE;
        p_ptr->wilderness_x = 49;
        p_ptr->wilderness_y = 11;
        p_ptr->town_num = 2;
        p_ptr->oldpx = px = 117;
        p_ptr->oldpy = py = 24;
        dun_level = 0;
	p_ptr->leaving = TRUE;

        cmsg_print(TERM_YELLOW, "'Turgon hails you.'");
        quest_describe(QUEST_INVASION);
        cquest.status = QUEST_STATUS_TAKEN;

        quick_messages = old_quick_messages;

        quest_invasion_init_hook(QUEST_INVASION);
        del_hook(HOOK_PLAYER_LEVEL, quest_invasion_plevel_hook);
        process_hooks_restart = TRUE;
        return (FALSE);
}
bool quest_invasion_dump_hook(int q_idx)
{
        if (cquest.status == QUEST_STATUS_FAILED)
        {
                fprintf(hook_file, "\n You abandoned Gondolin when it most needed you, thus causing its destruction.");
        }
        if ((cquest.status == QUEST_STATUS_FINISHED) || (cquest.status == QUEST_STATUS_REWARDED) || (cquest.status == QUEST_STATUS_COMPLETED))
        {
                fprintf(hook_file, "\n You saved Gondolin from destruction.");
        }
        return (FALSE);
}
bool quest_invasion_death_hook(int m_idx)
{
        int r_idx = m_list[m_idx].r_idx;

        if (p_ptr->inside_quest != QUEST_INVASION) return FALSE;

        if (r_idx == test_monster_name("Maeglin, the Traitor of Gondolin"))
        {
                cmsg_print(TERM_YELLOW, "You did it! Gondolin will remain hidden.");
                cquest.status = QUEST_STATUS_COMPLETED;
                del_hook(HOOK_MONSTER_DEATH, quest_invasion_death_hook);
                process_hooks_restart = TRUE;
                return (FALSE);
        }

        return FALSE;
}
bool quest_invasion_stair_hook(int down)
{
        if (p_ptr->inside_quest != QUEST_INVASION) return FALSE;

        if (cave[py][px].feat != FEAT_LESS) return TRUE;

        if (!down)
        {
                if (cquest.status == QUEST_STATUS_FAILED)
                {
                        cmsg_print(TERM_YELLOW, "The armies of Morgoth totaly desvasted Gondolin, leaving nothing but ruins...");
                }
                else if (cquest.status == QUEST_STATUS_COMPLETED)
                {
                        cmsg_print(TERM_YELLOW, "Turgon appears before you and speak:");
                        cmsg_print(TERM_YELLOW, "I will never be able to thank you enough.");
                        cmsg_print(TERM_YELLOW, "My most powerful mages wil cast a powerful spell for you, giving you 150 more life.");

                        p_ptr->hp_mod += 150;
                        p_ptr->update |= (PU_HP);
                        cquest.status = QUEST_STATUS_FINISHED;
                }
                else
                {
                        if (!get_check("Really abandon the quest?")) return TRUE;
                        cmsg_print(TERM_YELLOW, "You flee away from Maeglin and his army...");
                        cquest.status = QUEST_STATUS_FAILED;
                }
                del_hook(HOOK_STAIR, quest_invasion_stair_hook);
                process_hooks_restart = TRUE;
                return (FALSE);
        }

        return TRUE;
}
bool quest_invasion_init_hook(int q_idx)
{
        add_hook(HOOK_PLAYER_LEVEL, quest_invasion_plevel_hook, "invasion_plevel");
        add_hook(HOOK_CHAR_DUMP, quest_invasion_dump_hook, "invasion_dump");
        if ((cquest.status >= QUEST_STATUS_TAKEN) && (cquest.status < QUEST_STATUS_FINISHED))
        {
                add_hook(HOOK_MONSTER_AI, quest_invasion_ai_hook, "invasion_ai");
                add_hook(HOOK_GEN_QUEST, quest_invasion_gen_hook, "invasion_gen");
                add_hook(HOOK_MONSTER_DEATH, quest_invasion_death_hook, "invasion_death");
                add_hook(HOOK_STAIR, quest_invasion_stair_hook, "invasion_stair");
        }
        return (FALSE);
}
