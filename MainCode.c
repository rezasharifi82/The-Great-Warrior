#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <string.h>
#include "hash.c"

void must_init(bool test, const char *description)
{
    if (test)
        return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}
struct hero
{
    int honnor;
    int house_health;
    int damage;
    char name[20];
};
struct player
{
    int honnor;
    int house_health;
    int damage;
    char name[20];
    int pox; // to define the position of the players
    int poy;
};
int sugge(struct player c1, struct player c2, int nobat)
{
    int x, y;
    x = c1.pox;
    y = c1.poy;

    if (nobat == 1)
    {
        if (x < 5)
            al_draw_filled_rectangle((90 * y) + 155, (90 * (x + 1)) + 65.5, (90 * y) + 234, (90 * (x + 1)) + 145.4, al_map_rgb(102, 7, 52));
        if (x > 0)
            al_draw_filled_rectangle((90 * y) + 155, (90 * (x - 1)) + 65.5, (90 * y) + 234, (90 * (x - 1)) + 145.4, al_map_rgb(102, 7, 52));
        if (y > 0)
            al_draw_filled_rectangle((90 * (y - 1)) + 155, (90 * x) + 65.5, (90 * (y - 1)) + 234, (90 * x) + 145.4, al_map_rgb(102, 7, 52));
        if (y < 5)
            al_draw_filled_rectangle((90 * (y + 1)) + 155, (90 * x) + 65.5, (90 * (y + 1)) + 234, (90 * x) + 145.4, al_map_rgb(102, 7, 52));
    }
    int x2 = c2.pox;
    int y2 = c2.poy;
    if (nobat == 2)
    {
        if (x2 < 5 && x2 + 1 != x)
            al_draw_filled_rectangle((90 * y2) + 155, (90 * (x2 + 1)) + 65.5, (90 * y2) + 234, (90 * (x2 + 1)) + 145.4, al_map_rgb(102, 7, 52));
        if (x2 > 0 && x2 - 1 != x)
            al_draw_filled_rectangle((90 * y2) + 155, (90 * (x2 - 1)) + 65.5, (90 * y2) + 234, (90 * (x2 - 1)) + 145.4, al_map_rgb(102, 7, 52));
        if (y2 > 0 && y2 - 1 != y)
            al_draw_filled_rectangle((90 * (y2 - 1)) + 155, (90 * x2) + 65.5, (90 * (y2 - 1)) + 234, (90 * x2) + 145.4, al_map_rgb(102, 7, 52));
        if (y2 < 5 && y2 + 1 != y)
            al_draw_filled_rectangle((90 * (y2 + 1)) + 155, (90 * x2) + 65.5, (90 * (y2 + 1)) + 234, (90 * x2) + 145.4, al_map_rgb(102, 7, 52));
    }
    return 0;
}

void saveprotocol(struct player a, struct player b, int map[6][6])
{
    FILE *castola;
    castola = fopen("save.txt", "wt");
    char o[40];
    int k, temp1, temp2, temp3;
    for (int i = 0; i < 6; i++) ///mechanism of saving map;
    {
        for (int j = 0; j < 6; j++)
        {
            k = map[i][j];
            strcpy(o, hash(k));
            fprintf(castola, "%s\n", o);
        }
    }

    //////////////////player one without name
    temp1 = a.damage;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = a.honnor;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = a.house_health;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = a.pox;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = a.poy;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    ////////////////////player 2

    temp1 = b.damage;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = b.honnor;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = b.house_health;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = b.pox;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    temp1 = b.poy;
    strcpy(o, hash(temp1));
    fprintf(castola, "%s\n", o);
    ////////////////////////////////////names
    fprintf(castola, "%s\n", a.name);
    fprintf(castola, "%s\n", b.name);
    fclose(castola);
}

int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    must_init(queue, "queue");

    ALLEGRO_DISPLAY *disp = al_create_display(840, 660);
    must_init(disp, "display");
    al_init_font_addon();
    al_init_ttf_addon();
    ALLEGRO_FONT *font = al_load_font("reza.ttf", 72, 0);
    ALLEGRO_FONT *font1 = al_load_font("rez.ttf", 30, 0);
    ALLEGRO_FONT *font2 = al_load_font("f1.ttf", 50, 0);
    ALLEGRO_FONT *font3 = al_load_font("f2.ttf", 90, 0);
    ALLEGRO_FONT *font4 = al_load_font("f3.ttf", 50, 0);
    ALLEGRO_FONT *font5 = al_load_font("f2.ttf", 120, 0);
    //    ALLEGRO_FONT* font1 = al_load_font("rez.ttf",30,0);
    must_init(font, "font");
    must_init(font1, "font1");
    must_init(font2, "font2");
    must_init(font3, "font3");
    must_init(font4, "font4");

    must_init(al_init_image_addon(), "image addon");
    ALLEGRO_BITMAP *apple = al_load_bitmap("gknight.jpg");
    ALLEGRO_BITMAP *menu = al_load_bitmap("menu.jpg");
    ALLEGRO_BITMAP *hitle = al_load_bitmap("hitler.png");
    ALLEGRO_BITMAP *cyru = al_load_bitmap("cyrus.png");
    ALLEGRO_BITMAP *assa = al_load_bitmap("Assa.png");
    ALLEGRO_BITMAP *hear = al_load_bitmap("lion.png");
    ALLEGRO_BITMAP *p2 = al_load_bitmap("p2.jpg");
    ALLEGRO_BITMAP *mana = al_load_bitmap("mana.jpg");
    ALLEGRO_BITMAP *ws = al_load_bitmap("war.jpg");
    ALLEGRO_BITMAP *btf = al_load_bitmap("battle.jpg");
    ALLEGRO_BITMAP *one = al_load_bitmap("1.png");
    ALLEGRO_BITMAP *two = al_load_bitmap("2.png");
    ALLEGRO_BITMAP *battlefi = al_load_bitmap("battle.jpg");
    ALLEGRO_BITMAP *mainbo = al_load_bitmap("mainbo.jpg");

    must_init(menu, "menu");
    must_init(mainbo, "mainboard");
    must_init(p2, "p2menu");
    must_init(cyru, "cyrus");
    must_init(apple, "apple");
    must_init(mana, "mana");
    must_init(hitle, "hitler");
    must_init(assa, "assassins creed");
    must_init(hear, "lion heart richard");
    must_init(ws, "WarScence");
    must_init(btf, "Battlefield");
    must_init(battlefi, "final");

    struct hero hitler;
    hitler.damage = 7;
    hitler.house_health = 2000;
    strcpy(hitler.name, "Hitler");
    hitler.honnor = 10;
    struct hero cyrus;
    cyrus.damage = 10;
    cyrus.house_health = 1800;
    strcpy(cyrus.name, "Cyrus The Great");
    cyrus.honnor = 18;
    struct hero lion;
    lion.damage = 12;
    lion.honnor = 12;
    lion.house_health = 1000;
    strcpy(lion.name, "Lionheart Ricahrd");
    struct hero ezio; //as you know Ezio is an assassin :)
    ezio.damage = 13;
    ezio.honnor = 8;
    ezio.house_health = 1400;
    strcpy(ezio.name, "Ezio");
    struct player player1;
    player1.pox = 0;
    player1.poy = 0;
    struct player player2;
    player2.pox = 5;
    player2.poy = 5;

    int dmap[6][6] = {{0, 6, 0, 1, 8, 0},
                      {0, 7, 0, 0, 3, 0},
                      {9, 0, 2, 7, 0, 4},
                      {2, 0, 5, 6, 1, 0},
                      {3, 4, 0, 1, 0, 7},
                      {2, 8, 1, 0, 5, 0}};

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    int nobat = 1;
    int vaziat = 0;
    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;
    int fti = 0;
    ALLEGRO_KEYBOARD_STATE ks;
    al_start_timer(timer);
    time_t start = clock(), end = clock();
    int wpi = 0;
    char sto[20];
    while (1)
    { //Main Menu
        int dmap[6][6] = {{0, 6, 0, 1, 8, 0},
                          {0, 7, 0, 0, 3, 0},
                          {9, 0, 2, 7, 0, 4},
                          {2, 0, 5, 6, 1, 0},
                          {3, 4, 0, 1, 0, 7},
                          {2, 8, 1, 0, 5, 0}};
        if (fti == 0)
        {
        MAIN:

            fti = 0;
            al_draw_bitmap(apple, -390, -210, 0);
            al_draw_text(font, al_map_rgb(0, 0, 0), 50, 50, 0, "The Great Warrior");
            //al_draw_text(font3,al_map_rgb(126, 16, 8),100,430,0,"By: ");
            // al_draw_text(font2,al_map_rgb(7, 2, 37),40,550,0,"Mohammadreza");
            al_draw_text(font2, al_map_rgb(7, 2, 37), 0, 610 + 11, 0, "Dev:Sharifi Mohammadreza");
            end = clock();
            if (((end - start) / 20000) % 2 == 0)
            {
                al_draw_text(font1, al_map_rgb(126, 16, 8), 70, 300, 0, "Press Enter");
            }
            else
            {
                al_draw_text(font1, al_map_rgb(126, 16, 8), 70, 300, 0, " ");
            }
        }

        else if (fti == -1)
        {
        QUIT:
            al_clear_to_color(al_map_rgb(0, 5, 9));
            al_draw_text(font3, al_map_rgb(255, 240, 240), 30, 250 - 20, 0, "Really want to quit?");
            al_draw_text(font1, al_map_rgb(255, 200, 140), 200, 350 + 70, 0, "press Y to quit");
            al_draw_text(font1, al_map_rgb(255, 200, 140), 200, 400 + 70, 0, "or N to Comeback");
            al_get_keyboard_state(&ks);
            if (al_key_down(&ks, ALLEGRO_KEY_Y))
            {
                return 0;
            }
            al_get_keyboard_state(&ks);
            if (al_key_down(&ks, ALLEGRO_KEY_N))
            {
                fti = 0;
                continue;
            }
        }
        al_flip_display();
        al_get_keyboard_state(&ks);
        if (al_key_down(&ks, ALLEGRO_KEY_ENTER))
        {
            break;
            fti = 0;
        }
        al_get_keyboard_state(&ks);
        if (al_key_down(&ks, ALLEGRO_KEY_ESCAPE))
            fti = -1;
    }

    int elatsa = 1;
    while (1)
    {

        al_draw_bitmap(mana, -200, -100, 0);
        int elatsa = 1;

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
            int dmap[6][6] = {{0, 6, 0, 1, 8, 0},
                              {0, 7, 0, 0, 3, 0},
                              {9, 0, 2, 7, 0, 4},
                              {2, 0, 5, 6, 1, 0},
                              {3, 4, 0, 1, 0, 7},
                              {2, 8, 1, 0, 5, 0}};
            break;
        }
        else if (elatsa == 4)
        {
            start = clock();
            while (end - start < 620000)
            {
                int kola,stora;
                kola=20;
                stora=80;
                al_clear_to_color(al_map_rgb(31, 199, 87));
                al_draw_text(font1, al_map_rgb(7, 3, 61), 100, kola, 0, "This Project has made by:");
                al_draw_text(font, al_map_rgb(7, 3, 61), 80, kola+(1*stora), 0, "Mohammadreza Sharifi");
                al_draw_text(font1, al_map_rgb(7, 3, 61), 240, kola+(2*stora)+50, 0, "@FUM Jan 2022");
                al_draw_text(font4, al_map_rgb(7, 3, 61), 60, kola+(3*stora)+90, 0, "Contact info:");
                al_draw_text(font4, al_map_rgb(7, 3, 61), 20, kola+(4*stora)+90, 0, "sharifi.mohammadreza2002@gmail.com");
                al_draw_text(font4, al_map_rgb(7, 3, 61), 20, kola+(5*stora)+90, 0, "sharifi.mohammadreza@mail.um.ac.ir");
                al_draw_text(font4, al_map_rgb(7, 3, 61), 20, kola+(6*stora)+90, 0, "https://t.me/Maresha82");

                al_flip_display();
                end = clock();
            }
            goto MAIN;
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
                goto OONJA;
            }
            break;
        }

        else if (elatsa == 3)
        {
            goto MAIN;
        }
        else if (elatsa == 5)

        {
            fti = -1;
            goto QUIT;
        }
    }

NAMI:
    wpi = 1;
    al_get_keyboard_state(&ks);
    while (1)
    { //player one choosing mechanism
        al_draw_bitmap(menu, -200, 0, 0);
        if (wpi == 1)
        {
            al_draw_text(font1, al_map_rgb(250, 180, 165), 40, 30, 0, "Player1 Choose your character:");
            al_draw_text(font4, al_map_rgb(250, 180, 165), 20, 620, 0, "Work With Chars");
            al_draw_bitmap(hitle, 40, 100 - 20, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 38, 255, 0, "A.Hitler");
            al_draw_bitmap(cyru, 220, 100 - 30, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 220, 255, 0, "B.Cyrus");
            al_draw_bitmap(hear, 40, 300, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 8, 460, 0, "C.Richard");
            al_draw_bitmap(assa, 240, 301, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 250, 460, 0, "D.Ezio");
            al_flip_display();
        }

        al_get_keyboard_state(&ks);
        if (al_key_down(&ks, ALLEGRO_KEY_A))
        {
            player1.damage = hitler.damage;
            player1.honnor = hitler.honnor;
            player1.house_health = hitler.house_health;
            strcpy(player1.name, hitler.name);
            wpi = 2;
        }

        else if (al_key_down(&ks, ALLEGRO_KEY_B))
        {
            player1.damage = cyrus.damage;
            player1.honnor = cyrus.honnor;
            player1.house_health = cyrus.house_health;
            strcpy(player1.name, cyrus.name);
            wpi = 2;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_C))
        {
            player1.damage = lion.damage;
            player1.honnor = lion.honnor;
            player1.house_health = lion.house_health;
            strcpy(player1.name, lion.name);
            wpi = 2;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_D))
        {
            player1.damage = ezio.damage;
            player1.honnor = ezio.honnor;
            player1.house_health = ezio.house_health;
            strcpy(player1.name, ezio.name);
            wpi = 2;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_BACKSPACE))
        { // back mechanism
            goto MAIN;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_ENTER) == 0 && wpi != 2)
        {
            al_get_keyboard_state(&ks); //mechanism to ignore invalid input characters
        }

        if (wpi == 2)
            break;
    }
    wpi = 1;
    al_get_keyboard_state(&ks);
    while (1)
    { //player player 2 choosing mechanism
        al_draw_bitmap(p2, -800, -50, 0);
        if (wpi == 1)
        {
            al_draw_text(font1, al_map_rgb(250, 180, 165), 40, 30, 0, "Player2 Choose your character:");
            al_draw_text(font4, al_map_rgb(250, 180, 165), 20, 620, 0, "Work With Chars");
            al_draw_bitmap(assa, 40, 100 - 20, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 38 + 5, 245 - 5, 0, "M.Ezio");
            al_draw_bitmap(hear, 220, 100 - 30, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 205, 235, 0, "N.Richard");
            al_draw_bitmap(cyru, 40, 300, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 25, 460 + 40, 0, "X.Cyrus");
            al_draw_bitmap(hitle, 240, 301, 0);
            al_draw_text(font1, al_map_rgb(73, 3, 15), 240, 460, 0, "Y.Hitler");
            al_flip_display();
        }

        al_get_keyboard_state(&ks);
        if (al_key_down(&ks, ALLEGRO_KEY_Y))
        {
            player2.damage = hitler.damage;
            player2.honnor = hitler.honnor;
            player2.house_health = hitler.house_health;
            strcpy(player2.name, hitler.name);
            wpi = 2;
        }

        else if (al_key_down(&ks, ALLEGRO_KEY_X))
        {
            player2.damage = cyrus.damage;
            player2.honnor = cyrus.honnor;
            player2.house_health = cyrus.house_health;
            strcpy(player2.name, cyrus.name);
            wpi = 2;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_N))
        {
            player2.damage = lion.damage;
            player2.honnor = lion.honnor;
            player2.house_health = lion.house_health;
            strcpy(player2.name, lion.name);
            wpi = 2;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_M))
        {
            player2.damage = ezio.damage;
            player2.honnor = ezio.honnor;
            player2.house_health = ezio.house_health;
            strcpy(player2.name, ezio.name);
            wpi = 2;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_BACKSPACE))
        { // back mechanism
            goto NAMI;
        }
        else if (al_key_down(&ks, ALLEGRO_KEY_ENTER) == 0 && wpi != 2)
        {
            al_get_keyboard_state(&ks); //mechanism to ignore invalid input characters
        }

        if (wpi == 2)
            break;
    }

    start = clock();
    end = clock();
    while (end - start < 320000) //320000
    {                            //Last Check Menu

        al_draw_bitmap(ws, 0, -20, 0);
        al_draw_text(font2, al_map_rgb(14, 13, 105), 220 + 1, 40, 0, "Player1:");
        al_draw_text(font2, al_map_rgb(14, 13, 105), 220 + 5, 65, 0, "___");
        al_draw_text(font2, al_map_rgb(0, 7, 14), 10, 145, 0, "Name:  ");
        al_draw_text(font2, al_map_rgb(73, 3, 15), 160 + 40, 145, 0, player1.name);
        al_draw_text(font2, al_map_rgb(0, 7, 14), 10, 200, 0, "Damage:  ");
        sprintf(sto, "%d", player1.damage);
        al_draw_text(font2, al_map_rgb(73, 3, 15), 160 + 40, 200, 0, sto);
        al_draw_text(font2, al_map_rgb(0, 7, 14), 10, 280, 0, "honnor:  ");
        sprintf(sto, "%d", player1.honnor);
        al_draw_text(font2, al_map_rgb(73, 3, 15), 160 + 40, 280, 0, sto);
        al_draw_text(font2, al_map_rgb(0, 7, 14), 10, 340, 0, "Health:  ");
        sprintf(sto, "%d", player1.house_health);
        al_draw_text(font2, al_map_rgb(73, 3, 15), 160 + 40, 340, 0, sto);
        //////////////////////////////////////////////////////////////player2
        al_draw_text(font2, al_map_rgb(14, 13, 105), 560, 40, 0, "Player2:");
        al_draw_text(font2, al_map_rgb(14, 13, 105), 600 - 40, 65, 0, "___");
        al_draw_text(font2, al_map_rgb(73, 3, 15), 600 - 70, 145, 0, player2.name);
        sprintf(sto, "%d", player2.damage);
        al_draw_text(font2, al_map_rgb(73, 3, 15), 580, 200, 0, sto);
        sprintf(sto, "%d", player2.honnor);
        al_draw_text(font2, al_map_rgb(73, 3, 15), 580, 280, 0, sto);
        sprintf(sto, "%d", player2.house_health);
        al_draw_text(font2, al_map_rgb(73, 3, 15), 580, 340, 0, sto);
        sprintf(sto, "%ld", 8 - ((end - start) / 40000));
        al_draw_text(font5, al_map_rgb(78, 8, 3), 360, 500, 0, sto);
        al_flip_display();
        al_get_keyboard_state(&ks);
        if (al_key_down(&ks, ALLEGRO_KEY_BACKSPACE))
        {

            goto MAIN;
        }
        end = clock();
    }
OONJA:
    nobat = 1;
    int q = 0;
#define KEY_SEEN 1
#define KEY_RELEASED 2

    unsigned char key[ALLEGRO_KEY_MAX];
    memset(key, 0, sizeof(key));

    while (1)
    {
        al_wait_for_event(queue, &event);
        if (nobat == 1)
        {
            switch (event.type)
            {
            case ALLEGRO_EVENT_TIMER:

                if (key[ALLEGRO_KEY_UP])
                {
                    if (player1.pox > 0)
                    { //it can goes up
                        player1.pox -= 1;
                        int here = dmap[player1.pox][player1.poy];
                        if (here == 0)
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        else if (here <= 3)
                        {
                            player1.honnor += here;
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        }
                        else if (here <= 6)
                        {

                            player1.house_health += ((here - 3) * 100);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        }
                        else if (here <= 9)
                        {

                            player1.damage += (here - 6);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        }
                        nobat = 2;

                    } /////it can goes up
                    else
                    {
                        nobat = 1;
                    }

                } //allegro key up
                if (key[ALLEGRO_KEY_DOWN])
                {
                    if (player1.pox < 5)
                    { //it can goes down
                        player1.pox += 1;
                        int here = dmap[player1.pox][player1.poy];
                        if (here == 0)
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        else if (here <= 3)
                        {
                            player1.honnor += here;
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        }
                        else if (here <= 6)
                        {
                            player1.house_health += ((here - 3) * 100);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        }
                        else if (here <= 9)
                        {

                            player1.damage += (here - 6);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        }
                        nobat = 2;

                    } /////it can goes down
                    else
                    {
                        nobat = 1;
                    }
                } //key down finish

                if (key[ALLEGRO_KEY_LEFT])
                {
                    if (player1.poy > 0)
                    { //it can goes down
                        player1.poy -= 1;
                        int here = dmap[player1.pox][player1.poy];
                        if (here == 0)
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 6) % 10;
                        else if (here <= 3)
                        {
                            player1.honnor += here;
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 11) % 10;
                        }
                        else if (here <= 6)
                        {

                            player1.house_health += ((here - 3) * 100);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 7) % 10;
                        }
                        else if (here <= 9)
                        {

                            player1.damage += (here - 6);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 4) % 10;
                        }
                        nobat = 2;

                    } /////it can goes left
                    else
                    {
                        nobat = 1;
                    }
                }
                if (key[ALLEGRO_KEY_RIGHT])
                {
                    if (player1.poy < 5)
                    { //it can goes down
                        player1.poy += 1;
                        int here = dmap[player1.pox][player1.poy];
                        if (here == 0)
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 9) % 10;
                        else if (here < 4)
                        {
                            player1.honnor += here;
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 5) % 10;
                        }
                        else if (here < 7)
                        {

                            player1.house_health += ((here - 3) * 100);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 2) % 10;
                        }
                        else if (here < 10)
                        {

                            player1.damage += (here - 6);
                            dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + clock() % 4) % 10;
                        }
                        nobat = 2;
                    } /////it can goes right
                    else
                    {
                        nobat = 1;
                    }
                }

                if (key[ALLEGRO_KEY_ESCAPE])
                {

                    int vallahala = 1;

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

                                if (vallahala == 1)
                                    vallahala += 1;
                                else if (vallahala == 2)
                                    vallahala += 1;
                                else if (vallahala == 3)
                                    vallahala += 1;
                                else if (vallahala == 4)
                                    vallahala += 1;
                                else if (vallahala == 5)
                                    vallahala = 1;
                            }
                            else if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                            {
                                if (vallahala == 1)
                                    vallahala = 5;
                                else if (vallahala == 2)
                                    vallahala = 1;
                                else if (vallahala == 3)
                                    vallahala = 2;
                                else if (vallahala == 4)
                                    vallahala = 3;
                                else if (vallahala == 5)
                                    vallahala = 4;
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

                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 2)
                        {

                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 3)
                        {
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 4)
                        {
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 5)
                        {
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        al_flip_display();
                    } //while

                    if (vallahala == 1)
                    {
                        key[ALLEGRO_KEY_ESCAPE] = 0;
                    }
                    else if (vallahala == 2)
                    {
                        saveprotocol(player1, player2, dmap);
                    }
                    else if (vallahala == 3)
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

                    else if (vallahala == 4)
                    {
                        goto MAIN;
                    }
                    else if (vallahala == 5)

                    {
                        fti = -1;
                        goto QUIT;
                    }
                }
                if (key[ALLEGRO_KEY_L]) //attack
                {
                    player2.house_health -= ((player1.honnor) * player1.damage);
                    player1.damage /= 3;
                    player1.honnor /= 2;
                    nobat = 2;
                }

                for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= KEY_SEEN;

                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
                break;
            case ALLEGRO_EVENT_KEY_UP:
                key[event.keyboard.keycode] &= KEY_RELEASED;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fti = -1;
                goto QUIT;
                break;
            } ////switch

        } ///nobat 1
        else if (nobat == 2)
        {
            switch (event.type)
            {
            case ALLEGRO_EVENT_TIMER:

                if (key[ALLEGRO_KEY_W])
                {
                    if (player2.pox > 0)
                    { //it can goes up
                        player2.pox -= 1;
                        int here = dmap[player2.pox][player2.poy];
                        if (here == 0)
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 1) % 10;
                        else if (here <= 3)
                        {
                            player2.honnor += here;
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 2) % 10;
                        }
                        else if (here <= 6)
                        {

                            player2.house_health += ((here - 3) * 100);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 3) % 10;
                        }
                        else if (here <= 9)
                        {

                            player2.damage += (here - 6);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 4) % 10;
                        }

                        nobat = 1;

                    } /////it can goes up
                    else
                    {
                        nobat = 2;
                    }

                } //allegro key up
                if (key[ALLEGRO_KEY_S])
                {
                    if (player2.pox < 5)
                    { //it can goes down
                        player2.pox += 1;
                        int here = dmap[player2.pox][player2.poy];
                        if (here == 0)
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 1) % 10;
                        else if (here <= 3)
                        {
                            player2.honnor += here;
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 2) % 10;
                        }
                        else if (here <= 6)
                        {

                            player2.house_health += ((here - 3) * 100);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 3) % 10;
                        }
                        else if (here <= 9)
                        {

                            player1.damage += (here - 6);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 4) % 10;
                        }
                        nobat = 1;

                    } /////it can goes down
                    else
                    {
                        nobat = 2;
                    }
                } //key down finish

                if (key[ALLEGRO_KEY_A])
                {
                    if (player2.poy > 0)
                    { //it can goes down
                        player2.poy -= 1;
                        int here = dmap[player2.pox][player2.poy];
                        if (here == 0)
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 1) % 10;
                        else if (here <= 3)
                        {
                            player2.honnor += here;
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 2) % 10;
                        }
                        else if (here <= 6)
                        {

                            player2.house_health += ((here - 3) * 100);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 3) % 10;
                        }
                        else if (here <= 9)
                        {

                            player2.damage += (here - 6);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 4) % 10;
                        }

                        nobat = 1;
                    } /////it can goes down
                    else
                    {
                        nobat = 2;
                    }
                }

                if (key[ALLEGRO_KEY_D])
                {
                    if (player2.poy < 5)
                    { //it can goes down
                        player2.poy += 1;
                        int here = dmap[player2.pox][player2.poy];
                        if (here == 0)
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 1) % 10;
                        else if (here <= 3)
                        {
                            player2.honnor += here;
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 2) % 10;
                        }
                        else if (here <= 6)
                        {

                            player2.house_health += ((here - 3) * 100);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 3) % 10;
                        }
                        else if (here <= 9)
                        {

                            player2.damage += (here - 6);
                            dmap[player2.pox][player2.poy] = (dmap[player2.pox][player2.poy] + 4) % 10;
                        }

                        nobat = 1;

                    } /////it can goes down
                    else
                    {
                        nobat = 2;
                    }
                }
                if (key[ALLEGRO_KEY_ESCAPE])
                {

                    int vallahala = 1;

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

                                if (vallahala == 1)
                                    vallahala += 1;
                                else if (vallahala == 2)
                                    vallahala += 1;
                                else if (vallahala == 3)
                                    vallahala += 1;
                                else if (vallahala == 4)
                                    vallahala += 1;
                                else if (vallahala == 5)
                                    vallahala = 1;
                            }
                            else if (event.keyboard.keycode == ALLEGRO_KEY_UP)
                            {
                                if (vallahala == 1)
                                    vallahala = 5;
                                else if (vallahala == 2)
                                    vallahala = 1;
                                else if (vallahala == 3)
                                    vallahala = 2;
                                else if (vallahala == 4)
                                    vallahala = 3;
                                else if (vallahala == 5)
                                    vallahala = 4;
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

                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 2)
                        {

                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 3)
                        {
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 4)
                        {
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        else if (vallahala == 5)
                        {
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2, 0, "Resume");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + step, 0, "Save Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (2 * step), 0, "Load Game");
                            al_draw_text(font, al_map_rgb(i, j, k), ho1, ho2 + (3 * step), 0, "Main Menu");
                            al_draw_text(font, al_map_rgb(m, n, o), ho1, ho2 + (4 * step), 0, "Quit");
                        }
                        al_flip_display();
                    } //while

                    if (vallahala == 1)
                    {
                        key[ALLEGRO_KEY_ESCAPE] = 0;
                    }
                    else if (vallahala == 2)
                    {
                        saveprotocol(player1, player2, dmap);
                    }
                    else if (vallahala == 3)
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
                            //printf("lllllllllllllll");
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

                    else if (vallahala == 4)
                    {
                        goto MAIN;
                    }
                    else if (vallahala == 5)

                    {
                        fti = -1;
                        goto QUIT;
                    }
                }

                if (key[ALLEGRO_KEY_F]) //attack
                {
                    player1.house_health -= (((player2.honnor) * player2.damage));
                    player2.damage /= 3;
                    player2.honnor /= 2;
                    nobat = 1;
                }

                for (int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= KEY_SEEN;

                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
                key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;
                break;
            case ALLEGRO_EVENT_KEY_UP:
                key[event.keyboard.keycode] &= KEY_RELEASED;
                break;

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                fti = -1;
                goto QUIT;
                break;
            } ////switch

        } ////nobat 2
        if (done)
            break;

        if (redraw && al_is_event_queue_empty(queue))
        {
            int fx = 90 + 40 + 20;
            int fy = 60;
            int lenght = 110 - 20;
            int thickness = 8;
            al_draw_bitmap(mainbo, -410, -210, 0);
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    al_draw_rectangle(fx, fy, fx + lenght, fy + lenght, al_map_rgb(62, 78, 2), thickness);
                    fx += lenght;
                }
                fx -= 6 * lenght;
                fy += lenght;
            }

            //al_draw_text(font, al_map_rgb(255, 255, 255), 70, 0, 0, "Hello world!");
            int ox = player1.pox;
            int oy = player1.poy;
            int tx = player2.pox;
            int ty = player2.poy;
            int zar = 90.5;
            al_draw_filled_rectangle((zar * ty) + 155, (zar * tx) + 65.5, (zar * ty) + 234, (zar * tx) + 145.4, al_map_rgb(164, 164, 168));
            al_draw_filled_rectangle((zar * oy) + 155, (zar * ox) + 65.5, (zar * oy) + 234, (zar * ox) + 145.4, al_map_rgb(164, 164, 168));
            sugge(player1, player2, nobat);
            al_draw_text(font3, al_map_rgb(87, 1, 1), (90 * oy) + 180, (90 * ox) + 55, 0, "1");
            al_draw_text(font3, al_map_rgb(6, 2, 65), (90 * ty) + 180, (90 * tx) + 55, 0, "2");
            al_draw_text(font1, al_map_rgb(206, 193, 7), 10, 5, 0, "Honor");
            al_draw_text(font1, al_map_rgb(6, 248, 99), 340, 5, 0, "Health");
            al_draw_text(font1, al_map_rgb(206, 4, 4), 664, 5, 0, "Damage");
            if (1 == 1) //score board 1
            {
                al_draw_text(font2, al_map_rgb(8, 4, 226), 0, 100, 0, "Player1:");
                al_draw_text(font2, al_map_rgb(8, 4, 226), 0, 115, 0, "___");
                sprintf(sto, "%d", player1.honnor);
                al_draw_text(font2, al_map_rgb(206, 193, 7), 40, 170, 0, sto);
                sprintf(sto, "%d", player1.house_health);
                al_draw_text(font2, al_map_rgb(6, 248, 99), 40, 240, 0, sto);
                sprintf(sto, "%d", player1.damage);
                al_draw_text(font2, al_map_rgb(206, 4, 4), 40, 290 + 20, 0, sto);
            }
            if (2 == 2) ///score board 2
            {
                al_draw_text(font2, al_map_rgb(8, 4, 226), 700, 400 - 30, 0, "Player2:");
                al_draw_text(font2, al_map_rgb(8, 4, 226), 700, 415 - 30, 0, "___");
                sprintf(sto, "%d", player2.honnor);
                al_draw_text(font2, al_map_rgb(206, 193, 7), 745, 470 - 30, 0, sto);
                sprintf(sto, "%d", player2.house_health);
                al_draw_text(font2, al_map_rgb(6, 248, 99), 745, 540 - 30, 0, sto);
                sprintf(sto, "%d", player2.damage);
                al_draw_text(font2, al_map_rgb(206, 4, 4), 745, 610 - 30, 0, sto);
            }

            al_flip_display();

            redraw = false;
        }
        start = clock();
        al_get_keyboard_state(&ks);
        if (player2.house_health <= 0) ///////////////////////////////////////////////*****
        {
            while (1)
            {
                //player 1 win
                al_draw_bitmap(battlefi, -600, -150, 0);
                // al_draw_rectangle(200,200,400,400,al_map_rgb(15,25,45),70);
                al_draw_text(font, al_map_rgb(4, 2, 34), 70 + 20, 40 + 50, 0, "Congratulations Player 1");
                al_draw_text(font2, al_map_rgb(63, 4, 2), 70 + 20, 200, 0, "You can now leave this bloody battlefield");
                al_draw_text(font2, al_map_rgb(63, 4, 2), 70 - 20, 280, 0, "as The Greatest Warrior which has ever existed");
                end = clock();
                if (((end - start) / 30000) % 2 == 0)
                    al_draw_text(font1, al_map_rgb(4, 20, 34), 230, 370, 0, "Press Q to Quit");

                al_flip_display();
                al_get_keyboard_state(&ks);
                if (al_key_down(&ks, ALLEGRO_KEY_Q))
                {
                    goto MAIN;
                    break;
                }
            }
        }
        else if (player1.house_health <= 0)
        {
            while (1)
            {
                //player 2 win
                al_draw_bitmap(battlefi, -600, -150, 0);
                // al_draw_rectangle(200,200,400,400,al_map_rgb(15,25,45),70);
                al_draw_text(font, al_map_rgb(4, 2, 34), 70 + 20, 40 + 50, 0, "Congratulations Player 2");
                al_draw_text(font2, al_map_rgb(63, 4, 2), 70 + 20, 200, 0, "You can now leave this bloody battlefield");
                al_draw_text(font2, al_map_rgb(63, 4, 2), 70 - 20, 280, 0, "as The Greatest Warrior which has ever existed");
                end = clock();
                if (((end - start) / 30000) % 2 == 0)
                    al_draw_text(font1, al_map_rgb(4, 20, 34), 230, 370, 0, "Press Q to Quit");

                al_flip_display();
                al_get_keyboard_state(&ks);
                if (al_key_down(&ks, ALLEGRO_KEY_Q))
                {
                    goto MAIN;
                    break;
                }
            }
        }
    }

    al_destroy_bitmap(apple);
    al_destroy_bitmap(mainbo);
    al_destroy_bitmap(btf);
    al_destroy_bitmap(battlefi);
    al_destroy_bitmap(one);
    al_destroy_bitmap(two);
    al_destroy_bitmap(assa);
    al_destroy_bitmap(hear);
    al_destroy_bitmap(ws);
    al_destroy_bitmap(p2);
    al_destroy_bitmap(menu);
    al_destroy_bitmap(hitle);
    al_destroy_bitmap(cyru);
    al_destroy_font(font);
    al_destroy_font(font1);
    al_destroy_font(font2);
    al_destroy_font(font5);
    al_destroy_font(font3);
    al_destroy_font(font4);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}