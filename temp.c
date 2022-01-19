/*int vallahala = 1;
                    int x[3][3];
                    x[0][0] = 107; //red
                    x[0][1] = 5;
                    x[0][2] = 5;
                    //yellow 198, 231, 7
                    x[1][0] = 198;
                    x[1][1] = 231;
                    x[1][2] = 7;
                    x[2][0] = 198;
                    x[2][1] = 231;
                    x[2][2] = 7;
                    while (!al_key_down(&ks, ALLEGRO_KEY_SPACE))
                    {

                        int i = 198;
                        int j = 231;
                        int k = 7;
                        int ho1, ho2,step;
                        step=110;
                        ho1 = 250; ////x
                        ho2 = 200; ///y
                        int m, n, o;
                        m = 107;
                        n = 5;
                        o = 5;
                        al_wait_for_event(queue, &event);
                        al_get_keyboard_state(&ks);
                        switch (event.type)
                        {
                        case ALLEGRO_EVENT_KEY_DOWN:
                            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN)
                            {

                                if (vallahala == 1)
                                    vallahala += 1;
                                else if (vallahala == 2)
                                    vallahala += 1;
                                else
                                    vallahala = 1;
                            }
                            else if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                            {
                                if (vallahala == 1)
                                    vallahala = 3;
                                else if (vallahala == 2)
                                    vallahala = 1;
                                else
                                    vallahala = 2;
                            }
                            break;
                        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                            fti = -1;
                            goto QUIT;

                            break;
                        } //switch
                        al_clear_to_color(al_map_rgb(3, 1, 22));
                        if (vallahala == 1)
                        {
                            x[1][0] = i;
                            x[0][0] = m;
                            x[1][1] = j;
                            x[0][1] = n;
                            x[1][2] = k;
                            x[0][2] = o;
                            x[2][0] = i;
                            x[2][1] = j;
                            x[2][2] = k;
                            al_draw_text(font, al_map_rgb(x[0][0], x[0][1], x[0][2]), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(x[1][0], x[1][1], x[1][2]), ho1, ho2 + step, 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(x[2][0], x[2][1], x[2][2]), ho1, ho2 + (2*step), 0, "Quit");
                        }
                        if (vallahala == 2)
                        {
                            x[1][0] = m;
                            x[0][0] = i;
                            x[1][1] = n;
                            x[0][1] = j;
                            x[1][2] = o;
                            x[0][2] = k;
                            x[2][0] = i;
                            x[2][1] = j;
                            x[2][2] = k;
                            al_draw_text(font, al_map_rgb(x[0][0], x[0][1], x[0][2]), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(x[1][0], x[1][1], x[1][2]), ho1, ho2 + step, 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(x[2][0], x[2][1], x[2][2]), ho1, ho2 + (2*step), 0, "Quit");
                        }
                        if (vallahala == 3)
                        {
                            x[1][0] = i;
                            x[0][0] = i;
                            x[1][1] = j;
                            x[0][1] = j;
                            x[1][2] = k;
                            x[0][2] = k;
                            x[2][0] = m;
                            x[2][1] = n;
                            x[2][2] = o;
                            al_draw_text(font, al_map_rgb(x[0][0], x[0][1], x[0][2]), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(x[1][0], x[1][1], x[1][2]), ho1, ho2 + step, 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(x[2][0], x[2][1], x[2][2]), ho1, ho2 + (2*step), 0, "Quit");
                        }
                        al_flip_display();
                    } //while

                    if (vallahala == 2)
                    {
                        goto MAIN;
                    }
                    else if (vallahala == 3)

                    {
                        fti = -1;
                        goto QUIT;
                    }*/