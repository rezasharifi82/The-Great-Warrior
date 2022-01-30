/*int elatsa = 1;

while (!al_key_down(&ks, ALLEGRO_KEY_SPACE))
{

    int i = 198;
    int j = 231;
    int k = 7;
    int ho1, ho2, step;
    step = 120;
    ho1 = 280; ////x
    ho2 = 75;  ///y
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

            if (elatsa == 1)
                elatsa += 1;
            else if (elatsa == 2)
                elatsa += 1;
            else if (elatsa == 3)
                elatsa += 1;
            else if (elatsa == 4)
                elatsa += 1;
            else if (elatsa == 5)
                elatsa = 1;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_UP)
        {
            if (elatsa == 1)
                elatsa = 5;
            else if (elatsa == 2)
                elatsa = 1;
            else if (elatsa == 3)
                elatsa = 2;
            else if (elatsa == 4)
                elatsa = 3;
            else if (elatsa == 5)
                elatsa = 4;
        }
        break;
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
        fti = -1;
        goto QUIT;

        break;
    } //switch
    al_draw_bitmap(mana, -200, -100, 0);
    if (elatsa == 1)
    {

        al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2, 0, "New Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Load Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Back to First");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Developer Info");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
    }
    else if (elatsa == 2)
    {

        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "New Game");
        al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + step, 0, "Load Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Back to First");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Developer Info");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
    }
    else if (elatsa == 3)
    {
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "New Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Load Game");
        al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (2 * step), 0, "Back to First");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Developer Info");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
    }
    else if (elatsa == 4)
    {
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "New Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Load Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Back to First");
        al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (3 * step), 0, "Developer Info");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
    }
    else if (elatsa == 5)
    {
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "New Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Load Game");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Back to First");
        al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Developer Info");
        al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (4 * step), 0, "Quit");
    }
    al_flip_display();
} //while

if (elatsa == 1)
{
    dmap[6][6] = {{0, 6, 0, 1, 8, 0},
                  {0, 7, 0, 0, 3, 0},
                  {9, 0, 2, 7, 0, 4},
                  {2, 0, 5, 6, 1, 0},
                  {3, 4, 0, 1, 0, 7},
                  {2, 8, 1, 0, 5, 0}};
                  break;

}
else if (elatsa == 4)
{
    al_clear_to_color(al_map_rgb(31, 199, 87));
    
}
else if (elatsa == 2)
{
    if (1 == 1)
    {
        FILE *kurwa;
        int t1 = 0, t2, t3;
        char w[50], t21;
        kurwa = fopen("save.txt", "rt");
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                fscanf(kurwa, "%s", w);
                t1 = dhash(w);
                dmap[i][j] = t1;
            }
        }

        //////playerone
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player1.damage = t1;
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player1.honnor = t1;
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player1.house_health = t1;
        ////////////////////////////////////////////////////////////////////////
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player1.pox = t1;
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player1.poy = t1;
        //********************************************
        /////////player two
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player2.damage = t1;
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player2.honnor = t1;
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player2.house_health = t1;
        //*****************************************
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player2.pox = t1;
        fscanf(kurwa, "%s", w);
        t1 = dhash(w);
        player2.poy = t1;
        //*************************************************
        fscanf(kurwa, "%s", w);
        strcpy(player1.name, w);
        fscanf(kurwa, "%s", w);
        strcpy(player2.name, w);
        fclose(kurwa);
    }
}

else if (elatsa == 3)
{
    goto MAIN;
}
else if (elatsa == 5)

{
    fti = -1;
    goto QUIT;
}*/