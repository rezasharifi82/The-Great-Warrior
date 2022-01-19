#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <time.h>
#include <string.h>

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
int main()
{
    must_init(al_init(), "allegro");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 0.1);
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
    ALLEGRO_BITMAP *ws = al_load_bitmap("war.jpg");
    ALLEGRO_BITMAP *btf = al_load_bitmap("battle.jpg");
    ALLEGRO_BITMAP *one = al_load_bitmap("1.png");
    ALLEGRO_BITMAP *two = al_load_bitmap("2.png");

    must_init(menu, "menu");
    must_init(p2, "p2menu");
    must_init(cyru, "cyrus");
    must_init(apple, "apple");
    must_init(hitle, "hitler");
    must_init(assa, "assassins creed");
    must_init(hear, "lion heart richard");
    must_init(ws, "WarScence");
    must_init(btf, "Battlefield");
    must_init(one, "One");
    must_init(two, "Two");

    struct hero hitler;
    hitler.damage = 7;
    hitler.house_health = 200;
    strcpy(hitler.name, "Hitler");
    hitler.honnor = 10;
    struct hero cyrus;
    cyrus.damage = 10;
    cyrus.house_health = 180;
    strcpy(cyrus.name, "Cyrus The Great");
    cyrus.honnor = 18;
    struct hero lion;
    lion.damage = 12;
    lion.honnor = 12;
    lion.house_health = 100;
    strcpy(lion.name, "Lionheart Ricahrd");
    struct hero ezio; //as you know Ezio is an assassin :)
    ezio.damage = 13;
    ezio.honnor = 8;
    ezio.house_health = 140;
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
    char sto[20]; /*
                while(1){  //Main Menu
                if(fti==0){
                
                MAIN:
                fti=0;
                al_draw_bitmap(apple, -390, -210, 0);
                al_draw_text(font,al_map_rgb(0,0,0),50,50,0,"The Great Warrior");
                //al_draw_text(font3,al_map_rgb(126, 16, 8),100,430,0,"By: ");
               // al_draw_text(font2,al_map_rgb(7, 2, 37),40,550,0,"Mohammadreza");
                al_draw_text(font2,al_map_rgb(7, 2, 37),0,610+11,0,"Sharifi");
                end=clock();
                if(((end-start)/20000)%2==0){
                al_draw_text(font1,al_map_rgb(126, 16, 8),70,300,0,"Press Enter");
                }
                else{
                    al_draw_text(font1,al_map_rgb(126, 16, 8),70,300,0," ");
                }
                }

                else if(fti==-1){
                    al_clear_to_color(al_map_rgb(0,5,9));
                    al_draw_text(font3,al_map_rgb(255,240,240),30,250-20,0,"Really want to quit?");
                    al_draw_text(font1,al_map_rgb(255,200,140),200,350+70,0,"press Y to quit");
                    al_draw_text(font1,al_map_rgb(255,200,140),200,400+70,0,"or N to Comeback");
                    al_get_keyboard_state(&ks);
                    if(al_key_down(&ks,ALLEGRO_KEY_Y)){
                        return 0;
                    }
                    al_get_keyboard_state(&ks);
                    if(al_key_down(&ks,ALLEGRO_KEY_N)){
                        fti=0;
                        continue;
                    }
                }
                al_flip_display();
                al_get_keyboard_state(&ks);
                if(al_key_down(&ks,ALLEGRO_KEY_ENTER)){
                    break;
                    fti=0;
                }
                al_get_keyboard_state(&ks);
                if(al_key_down(&ks,ALLEGRO_KEY_ESCAPE))
                    fti=-1;
                    
            }
NAMI:
wpi=1;
al_get_keyboard_state(&ks);
    while(1){ //player one choosing mechanism
        al_draw_bitmap(menu,-200,0,0);
        if(wpi==1){
        al_draw_text(font1,al_map_rgb(250,180,165),40,30,0,"Player1 Choose your character:");
        al_draw_text(font4,al_map_rgb(250,180,165),20,620,0,"Work With Chars");
        al_draw_bitmap(hitle,40,100-20,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),38,255,0,"A.Hitler");
        al_draw_bitmap(cyru,220,100-30,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),220,255,0,"B.Cyrus");
        al_draw_bitmap(hear,40,300,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),8,460,0,"C.Richard");
        al_draw_bitmap(assa,240,301,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),250,460,0,"D.Ezio");
        al_flip_display();
        }
        

        
        
        
        al_get_keyboard_state(&ks);
        if(al_key_down(&ks,ALLEGRO_KEY_A)){
            player1.damage=hitler.damage;
            player1.honnor=hitler.honnor;
            player1.house_health=hitler.house_health;
            strcpy(player1.name,hitler.name);
            wpi=2;
        }
        
        else if(al_key_down(&ks,ALLEGRO_KEY_B)){
            player1.damage=cyrus.damage;
            player1.honnor=cyrus.honnor;
            player1.house_health=cyrus.house_health;
            strcpy(player1.name,cyrus.name);
            wpi=2;

        }
        else if(al_key_down(&ks,ALLEGRO_KEY_C)){
            player1.damage=lion.damage;
            player1.honnor=lion.honnor;
            player1.house_health=lion.house_health;
            strcpy(player1.name,lion.name);
            wpi=2;

        }
        else if(al_key_down(&ks,ALLEGRO_KEY_D)){
            player1.damage=ezio.damage;
            player1.honnor=ezio.honnor;
            player1.house_health=ezio.house_health;
            strcpy(player1.name,ezio.name);
            wpi=2;
        }
        else if(al_key_down(&ks,ALLEGRO_KEY_BACKSPACE)){ // back mechanism
            goto MAIN;
        }
        else if(al_key_down(&ks,ALLEGRO_KEY_ENTER)==0 && wpi!=2){       
            al_get_keyboard_state(&ks); //mechanism to ignore invalid input characters
        }
        
    
    
    if(wpi==2)
    break;
    }
wpi=1;
al_get_keyboard_state(&ks);
    while(1){ //player player 2 choosing mechanism
        al_draw_bitmap(p2,-800,-50,0);
        if(wpi==1){
        al_draw_text(font1,al_map_rgb(250,180,165),40,30,0,"Player1 Choose your character:");
        al_draw_text(font4,al_map_rgb(250,180,165),20,620,0,"Work With Chars");
        al_draw_bitmap(assa,40,100-20,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),38+5,245-5,0,"E.Ezio");
        al_draw_bitmap(hear,220,100-30,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),205,235,0,"F.Richard");
        al_draw_bitmap(cyru,40,300,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),25,460+40,0,"G.Cyrus");
        al_draw_bitmap(hitle,240,301,0);
        al_draw_text(font1,al_map_rgb(73, 3, 15),240,460,0,"H.Hitler");
        al_flip_display();
        }
        
        al_get_keyboard_state(&ks);
        if(al_key_down(&ks,ALLEGRO_KEY_H)){
            player2.damage=hitler.damage;
            player2.honnor=hitler.honnor;
            player2.house_health=hitler.house_health;
            strcpy(player2.name,hitler.name);
            wpi=2;
        }
        
        else if(al_key_down(&ks,ALLEGRO_KEY_G)){
            player2.damage=cyrus.damage;
            player2.honnor=cyrus.honnor;
            player2.house_health=cyrus.house_health;
            strcpy(player2.name,cyrus.name);
            wpi=2;

        }
        else if(al_key_down(&ks,ALLEGRO_KEY_F)){
            player2.damage=lion.damage;
            player2.honnor=lion.honnor;
            player2.house_health=lion.house_health;
            strcpy(player2.name,lion.name);
            wpi=2;

        }
        else if(al_key_down(&ks,ALLEGRO_KEY_E)){
            player2.damage=ezio.damage;
            player2.honnor=ezio.honnor;
            player2.house_health=ezio.house_health;
            strcpy(player2.name,ezio.name);
            wpi=2;
        }
        else if(al_key_down(&ks,ALLEGRO_KEY_BACKSPACE)){ // back mechanism
            goto NAMI;
        }
        else if(al_key_down(&ks,ALLEGRO_KEY_ENTER)==0 && wpi!=2){       
            al_get_keyboard_state(&ks); //mechanism to ignore invalid input characters
        }
        
    
    
    if(wpi==2)
    break;
    }  


start=clock();
end=clock();
    while(end-start<320000){ //Last Check Menu
        
        al_draw_bitmap(ws,0,-20,0);
        al_draw_text(font2,al_map_rgb(14, 13, 105),220+1,40,0,"Player1:");
        al_draw_text(font2,al_map_rgb(14, 13, 105),220+5,65,0,"___");
        al_draw_text(font2,al_map_rgb(0,7,14),10,145,0,"Name:  ");
        al_draw_text(font2,al_map_rgb(73,3,15),160+40,145,0,player1.name);
        al_draw_text(font2,al_map_rgb(0,7,14),10,200,0,"Damage:  ");
        sprintf(sto,"%d",player1.damage);
        al_draw_text(font2,al_map_rgb(73,3,15),160+40,200,0,sto);
        al_draw_text(font2,al_map_rgb(0,7,14),10,280,0,"honnor:  ");
        sprintf(sto,"%d",player1.honnor);
        al_draw_text(font2,al_map_rgb(73,3,15),160+40,280,0,sto);
        al_draw_text(font2,al_map_rgb(0,7,14),10,340,0,"Health:  ");
        sprintf(sto,"%d",player1.house_health);
        al_draw_text(font2,al_map_rgb(73,3,15),160+40,340,0,sto);
        //////////////////////////////////////////////////////////////player2
        al_draw_text(font2,al_map_rgb(14, 13, 105),560,40,0,"Player2:");
        al_draw_text(font2,al_map_rgb(14, 13, 105),600-40,65,0,"___");
        al_draw_text(font2,al_map_rgb(73,3,15),600-70,145,0,player2.name);
        sprintf(sto,"%d",player2.damage);
        al_draw_text(font2,al_map_rgb(73,3,15),580,200,0,sto);
        sprintf(sto,"%d",player2.honnor);
        al_draw_text(font2,al_map_rgb(73,3,15),580,280,0,sto);
        sprintf(sto,"%d",player2.house_health);
        al_draw_text(font2,al_map_rgb(73,3,15),580,340,0,sto);
        sprintf(sto,"%ld",8-((end-start)/40000));
        al_draw_text(font5,al_map_rgb(78, 8, 3),360,500,0,sto);
        al_flip_display();
        al_get_keyboard_state(&ks);
        if(al_key_down(&ks,ALLEGRO_KEY_BACKSPACE)){

            goto MAIN;
        }
    end=clock();
    }
     */
                  /////////////////////////////////////////////////////////////////////////////////////////////
    nobat = 1;
    int q = 0;
    while (1)
    {
        //jadval va grpahic main

        al_clear_to_color(al_map_rgb(156, 167, 12));

        int fx = 90 + 40 + 20;
        int fy = 60;
        int lenght = 110 - 20;
        int thickness = 6;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                al_draw_rectangle(fx, fy, fx + lenght, fy + lenght, al_map_rgb(126, 16, 8), thickness);
                fx += lenght;
            }
            fx -= 6 * lenght;
            fy += lenght;
        }
        al_draw_text(font3, al_map_rgb(0, 0, 0), (90 * player1.pox) + 180, (90 * player1.poy) + 55, 0, "1");
        al_draw_text(font3, al_map_rgb(0, 0, 0), (90 * player2.pox) + 180, (90 * player2.poy) + 55, 0, "2");

        al_flip_display();
        al_get_keyboard_state(&ks);
        if (nobat == 1)
        {
            if (al_key_down(&ks, ALLEGRO_KEY_W))
            { //goes up
                if (player1.poy > 0)
                { //it can goes up
                    player1.poy -= 1;
                    int here = dmap[player1.pox][player1.poy];
                    if (here == 0)
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 1) % 10;
                    else if (here <= 3)
                    {
                        player1.honnor += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 2) % 10;
                    }
                    else if (here <= 6)
                    {
                        here %= 3;
                        player1.house_health += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 3) % 10;
                    }
                    else if (here <= 9)
                    {
                        here %= 3;
                        player1.damage += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 4) % 10;
                    }
                    ///////// nobat=2;
                } //it can goes up

                //not valid move

            } //key w

            else if (al_key_down(&ks, ALLEGRO_KEY_S))
            { //goes down
                if (player1.poy < 5)
                { //it can goes down
                    player1.poy += 1;
                    int here = dmap[player1.pox][player1.poy];
                    if (here == 0)
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 1) % 10;
                    else if (here <= 3)
                    {
                        player1.honnor += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 2) % 10;
                    }
                    else if (here <= 6)
                    {
                        here %= 3;
                        player1.house_health += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 3) % 10;
                    }
                    else if (here <= 9)
                    {
                        here %= 3;
                        player1.damage += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 4) % 10;
                    }
                    /////////       nobat=2;
                } //it can goes down

                //not valid move

            } //key s

            else if (al_key_down(&ks, ALLEGRO_KEY_D))
            { //goes right
                if (player1.pox < 5)
                { //it can goes right
                    player1.pox += 1;
                    int here = dmap[player1.pox][player1.poy];
                    if (here == 0)
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 1) % 10;
                    else if (here <= 3)
                    {
                        player1.honnor += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 2) % 10;
                    }
                    else if (here <= 6)
                    {
                        here %= 3;
                        player1.house_health += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 3) % 10;
                    }
                    else if (here <= 9)
                    {
                        here %= 3;
                        player1.damage += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 4) % 10;
                    }
                    //        //// nobat=2;
                } //it can goes right

                //not valid move

            } //key D

            else if (al_key_down(&ks, ALLEGRO_KEY_A))
            { //ges left
                if (player1.pox > 0)
                { //it can goes up
                    player1.pox -= 1;
                    int here = dmap[player1.pox][player1.poy];
                    if (here == 0)
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 1) % 10;
                    else if (here <= 3)
                    {
                        player1.honnor += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 2) % 10;
                    }
                    else if (here <= 6)
                    {
                        here %= 3;
                        player1.house_health += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 3) % 10;
                    }
                    else if (here <= 9)
                    {
                        here %= 3;
                        player1.damage += here;
                        dmap[player1.pox][player1.poy] = (dmap[player1.pox][player1.poy] + 4) % 10;
                    }
                    /////nobat=2;
                } //it can goes left

                //not valid move
            } //key A

            else
            {
                nobat = 1;
                /*char ioi[30];
                    sprintf(ioi,"%d",player1.pox);
                    al_draw_text(font,al_map_rgb(0,0,0),0,5,0,"Nobat 1");
                    al_draw_text(font,al_map_rgb(0,0,0),0,125,0,ioi);
                    sprintf(ioi,"%d",player1.poy);
                    al_draw_text(font,al_map_rgb(0,0,0),0,245,0,ioi);
                    al_flip_display();*/
            }
            //write else for waiting for movement

        } //nobat1

        /*    else if(nobat==2){
                if(al_key_down(&ks,ALLEGRO_KEY_UP)){ //goes up
                    if(player2.poy>0){ //it can goes up
                        player2.poy-=1;
                    int here= dmap[player2.pox][player2.poy];
                    if(here==0)
                    dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+1)%10;
                    else if(here<=3){
                        player2.honnor+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+2)%10;
                    }
                    else if(here<=6){
                        here%=3;
                        player2.house_health+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+3)%10;
                    }
                    else if(here<=9){
                        here%=3;
                        player1.damage+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+4)%10;
                    }
                    nobat=2;
                }//it can goes up

                //not valid move

                }//key arrow up


                else if(al_key_down(&ks,ALLEGRO_KEY_DOWN)){ //goes down
                    if(player2.poy<5){ //it can goes down
                        player2.poy+=1;
                    int here= dmap[player1.pox][player1.poy];
                    if(here==0)
                    dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+1)%10;
                    else if(here<=3){
                        player2.honnor+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+2)%10;
                    }
                    else if(here<=6){
                        here%=3;
                        player1.house_health+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+3)%10;
                    }
                    else if(here<=9){
                        here%=3;
                        player1.damage+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+4)%10;
                    }
                    nobat=2;
                }//it can goes down

                //not valid move

                }//key down


                else if(al_key_down(&ks,ALLEGRO_KEY_RIGHT)){ //goes right
                    if(player2.pox<5){ //it can goes right
                        player2.pox+=1;
                    int here= dmap[player2.pox][player2.poy];
                    if(here==0)
                    dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+1)%10;
                    else if(here<=3){
                        player1.honnor+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+2)%10;
                    }
                    else if(here<=6){
                        here%=3;
                        player2.house_health+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+3)%10;
                    }
                    else if(here<=9){
                        here%=3;
                        player1.damage+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+4)%10;
                    }
                    nobat=2;
                }//it can goes right

                //not valid move

                }//key right

               else if(al_key_down(&ks,ALLEGRO_KEY_LEFT)){ //goes left
                    if(player2.pox>0){ //it can goes up
                        player2.pox-=1;
                    int here= dmap[player2.pox][player2.poy];
                    if(here==0)
                    dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+1)%10;
                    else if(here<=3){
                        player2.honnor+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+2)%10;
                    }
                    else if(here<=6){
                        here%=3;
                        player1.house_health+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+3)%10;
                    }
                    else if(here<=9){
                        here%=3;
                        player1.damage+=here;
                        dmap[player2.pox][player2.poy]=(dmap[player2.pox][player2.poy]+4)%10;
                    }
                    nobat=2;
                }//it can goes left

                //not valid move
                }//key left


                else{
                    nobat=2;
                    al_draw_text(font,al_map_rgb(0,0,0),0,25,0,"Nobat 2");
                    al_flip_display();
                }












            }//nobat2*/

        ///////////////////////////////////////////////////////////////////////////////////

    } //while(1)

    al_destroy_bitmap(apple);
    al_destroy_bitmap(btf);
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