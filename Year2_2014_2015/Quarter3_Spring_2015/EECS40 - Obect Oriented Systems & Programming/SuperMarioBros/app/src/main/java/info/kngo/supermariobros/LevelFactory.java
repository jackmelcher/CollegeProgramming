package info.kngo.supermariobros;

import android.graphics.Canvas;

import java.lang.reflect.Array;
import java.util.ArrayList;

/**
 * Created by Kevin on 5/11/2015.
 */
public class LevelFactory implements TimeConscious {

    //DashTillPuffSurfaceView
    MarioSurfaceView view;
    private int screenW, screenH;
    private int marioSize;
    int pitFallWidth ;

    //Array list for clusters
    public ArrayList<Enemy> enemies;
    public ArrayList<Item> items;
    public ArrayList<Block> floors;
    public ArrayList<Block> blocks;

    //Object declarations
    Block floor0;
    Block floor1;
    Block floor2;

    Block breakable_block0;
    Block breakable_block1;
    Block breakable_block2;
    Block breakable_block3;
    Block breakable_block4;
    Block breakable_block5;
    Block breakable_block6;
    Block breakable_block7;
    Block breakable_block8;
    Block breakable_block9;
    Block breakable_block10;
    Block breakable_block11;

    Block item_block0;
    Block item_block1;
    Block item_block2;

    Item coin0;
    Item coin1;
    Item coin2;
    Item coin3;
    Item coin4;
    Item coin5;
    Item coin6;
    Item coin7;
    Item coin8;
    Item coin9;
    Item coin10;
    Item coin11;
    Item coin12;
    Item coin13;
    Item coin14;
    Item coin15;

    Enemy goomba0;
    Enemy goomba1;
    Enemy goomba2;
    Enemy goomba3;
    Enemy goomba4;
    Enemy goomba5;
    Enemy goomba6;

    Enemy koopa0;
    Enemy koopa1;
    Enemy koopa2;
    Enemy koopa3;
    Enemy koopa4;
    Enemy koopa5;
    Enemy koopa6;

    //Constructor
    LevelFactory(MarioSurfaceView view, int level) {
        this.view = view;
        this.enemies = new ArrayList<>();
        this.items = new ArrayList<>();
        this.floors = new ArrayList<>();
        this.blocks = new ArrayList<>();

        //Screen Width
        screenW = view.getWidth();
        //Screen Height
        screenH = view.getHeight();
        //Standard size of mario proportional to screen
        marioSize = screenH/20;
        //Width of pitfalls
        this.pitFallWidth = 7*marioSize;

        if(level == 1){
            // Create game objects
            //floors
            floor0 = new Block(view,0, 18*marioSize, 3, 3);
            floor1 = new Block(view,screenW-marioSize, 18*marioSize, 3, 3);
            floor2 = new Block(view,2*screenW-marioSize, 18*marioSize, 3, 3);
            floors.add(floor0);
            floors.add(floor1);
            floors.add(floor2);

            //Screen 1
            breakable_block0 = new Block(view, 0*screenW+10*marioSize, 13*marioSize, 0, 0);
            breakable_block1 = new Block(view, 0*screenW+11*marioSize, 13*marioSize, 0, 0);
            breakable_block2 = new Block(view, 0*screenW+14*marioSize, 13*marioSize, 0, 0);
            item_block0 = new Block(view, 0*screenW+12*marioSize, 8*marioSize, 1, 0);
            item_block1 = new Block(view, 0*screenW+12*marioSize, 13*marioSize, 1, 1);
            item_block2 = new Block(view, 0*screenW+13*marioSize, 13*marioSize, 1, 0);
            blocks.add(breakable_block0);
            blocks.add(breakable_block1);
            blocks.add(breakable_block2);
            blocks.add(item_block0);
            blocks.add(item_block1);
            blocks.add(item_block2);
            goomba0 = new Enemy(view, 0*screenW+25*marioSize, 17*marioSize, 0);
            goomba1 = new Enemy(view, 0*screenW+27*marioSize, 17*marioSize, 0);
            enemies.add(goomba0);
            enemies.add(goomba1);

            //Screen 2
            koopa0 = new Enemy(view, 1*screenW+5*marioSize, 17*marioSize, 1);
            koopa1 = new Enemy(view, 1*screenW+7*marioSize, 17*marioSize, 1);
            enemies.add(koopa0);
            enemies.add(koopa1);
            coin0 = new Item(view, 1*screenW+14*marioSize, 8*marioSize, 0);
            coin1 = new Item(view, 1*screenW+15*marioSize, 8*marioSize, 0);
            coin2 = new Item(view, 1*screenW+16*marioSize, 8*marioSize, 0);
            items.add(coin0);
            items.add(coin1);
            items.add(coin2);
            breakable_block3 = new Block(view, 1*screenW+14*marioSize, 13*marioSize, 0, 0);
            breakable_block4 = new Block(view, 1*screenW+15*marioSize, 13*marioSize, 0, 0);
            breakable_block5 = new Block(view, 1*screenW+16*marioSize, 13*marioSize, 0, 0);
            blocks.add(breakable_block3);
            blocks.add(breakable_block4);
            blocks.add(breakable_block5);
            goomba2 = new Enemy(view, 1*screenW+25*marioSize, 17*marioSize, 0);
            goomba3 = new Enemy(view, 1*screenW+27*marioSize, 17*marioSize, 0);
            goomba4 = new Enemy(view, 1*screenW+29*marioSize, 17*marioSize, 0);
            enemies.add(goomba2);
            enemies.add(goomba3);
            enemies.add(goomba4);


            //Screen 3
            koopa2 = new Enemy(view, 2*screenW+1*marioSize, 17*marioSize, 1);
            koopa3 = new Enemy(view, 2*screenW+5*marioSize, 17*marioSize, 1);
            koopa4 = new Enemy(view, 2*screenW+10*marioSize, 17*marioSize, 1);
            enemies.add(koopa2);
            enemies.add(koopa3);
            enemies.add(koopa4);
            breakable_block6 = new Block(view, 2*screenW+10*marioSize, 14*marioSize, 0, 0);
            breakable_block7 = new Block(view, 2*screenW+11*marioSize, 14*marioSize, 0, 0);
            breakable_block8 = new Block(view, 2*screenW+15*marioSize, 10*marioSize, 0, 0);
            breakable_block9 = new Block(view, 2*screenW+16*marioSize, 10*marioSize, 0, 0);
            breakable_block10 = new Block(view, 2*screenW+20*marioSize, 6*marioSize, 0, 0);
            breakable_block11 = new Block(view, 2*screenW+21*marioSize, 6*marioSize, 0, 0);
            blocks.add(breakable_block6);
            blocks.add(breakable_block7);
            blocks.add(breakable_block8);
            blocks.add(breakable_block9);
            blocks.add(breakable_block10);
            blocks.add(breakable_block11);
            coin3 = new Item(view, 2*screenW+11*marioSize, 13*marioSize, 0);
            coin4 = new Item(view, 2*screenW+16*marioSize, 9*marioSize, 0);
            coin5 = new Item(view, 2*screenW+21*marioSize, 5*marioSize, 0);
            items.add(coin3);
            items.add(coin4);
            items.add(coin5);
        }
        if(level == 2){

            floor0 = new Block(view,0, 18*marioSize, 3, 3);
            floor1 = new Block(view,screenW-marioSize + pitFallWidth, 18*marioSize, 3, 3);
            floor2 = new Block(view,2*screenW-marioSize, 18*marioSize, 3, 3);

            floors.add(floor0);
            floors.add(floor1);
            floors.add(floor2);



            coin0 = new Item(view, 12*marioSize, 13*marioSize, 0);
            coin1 = new Item(view, 13*marioSize, 13*marioSize, 0);
            coin2 = new Item(view, 14*marioSize, 13*marioSize, 0);
            items.add(coin0);
            items.add(coin1);
            items.add(coin2);

            //Elements for floor 0; 0 < x < screenWidth (1920)
            coin0 = new Item(view, 15*marioSize, 13*marioSize, 0);
            coin1 = new Item(view, 16*marioSize, 13*marioSize, 0);
            coin2 = new Item(view, 17*marioSize, 13*marioSize, 0);
            items.add(coin0);
            items.add(coin1);
            items.add(coin2);


            item_block0 = new Block(view, 20*marioSize, 13*marioSize, 1, 0);
            item_block1 = new Block(view, 21*marioSize, 13*marioSize, 1, 1);
            item_block2 = new Block(view, 22*marioSize, 13*marioSize, 1, 0);
            blocks.add(item_block0);
            blocks.add(item_block1);
            blocks.add(item_block2);

            goomba1 = new Enemy(view, 27*marioSize, 17*marioSize, 0);
            goomba2 = new Enemy(view, 28*marioSize, 17*marioSize, 0);
            goomba3 = new Enemy(view, 29*marioSize, 17*marioSize, 0);
            enemies.add(goomba1);
            enemies.add(goomba2);
            enemies.add(goomba3);


            //Elements for floor1; screenWidth + pitfallWidth (2298)< x < 2*screenWidth (4272)
            koopa0 = new Enemy(view, 69*marioSize, 17*marioSize, 1);
            koopa1 = new Enemy(view, 70*marioSize, 17*marioSize, 1);
            koopa2 = new Enemy(view, 71*marioSize, 17*marioSize, 1);
            enemies.add(koopa0);
            enemies.add(koopa1);
            enemies.add(koopa2);

            item_block0 = new Block(view, 56*marioSize, 13*marioSize, 1, 0);
            item_block1 = new Block(view, 57*marioSize, 13*marioSize, 1, 2);
            item_block2 = new Block(view, 58*marioSize, 13*marioSize, 1, 0);
            blocks.add(item_block0);
            blocks.add(item_block1);
            blocks.add(item_block2);

            coin0 = new Item(view, 58*marioSize, 5*marioSize, 0);
            coin1 = new Item(view, 59*marioSize, 5*marioSize, 0);
            coin2 = new Item(view, 60*marioSize, 5*marioSize, 0);
            items.add(coin0);
            items.add(coin1);
            items.add(coin2);

            breakable_block0 = new Block(view, 61*marioSize, 8*marioSize, 0, 0);
            breakable_block1 = new Block(view, 62*marioSize, 8*marioSize, 0, 0);
            breakable_block2 = new Block(view, 63*marioSize, 8*marioSize, 0, 0);
            breakable_block3 = new Block(view, 64*marioSize, 8*marioSize, 0, 0);
            blocks.add(breakable_block0);
            blocks.add(breakable_block1);
            blocks.add(breakable_block2);
            blocks.add(breakable_block3);


            coin0 = new Item(view, 65*marioSize, 7*marioSize, 0);
            coin1 = new Item(view, 66*marioSize, 6*marioSize, 0);
            coin2 = new Item(view, 67*marioSize, 5*marioSize, 0);
            items.add(coin0);
            items.add(coin1);
            items.add(coin2);
            coin0 = new Item(view, 68*marioSize, 5*marioSize, 0);
            coin1 = new Item(view, 69*marioSize, 6*marioSize, 0);
            coin2 = new Item(view, 70*marioSize, 7*marioSize, 0);
            items.add(coin0);
            items.add(coin1);
            items.add(coin2);

            //Elements for floor 2; 4272 < x < 6246

            breakable_block0 = new Block(view, 93*marioSize, 13*marioSize, 0, 0);
            breakable_block9 = new Block(view, 98*marioSize, 11*marioSize, 0, 0);
            blocks.add(breakable_block0);
            blocks.add(breakable_block9);


            breakable_block0 = new Block(view, 102*marioSize, 8*marioSize, 0, 0);
            breakable_block1 = new Block(view, 103*marioSize, 8*marioSize, 0, 0);
            breakable_block2 = new Block(view, 104*marioSize, 8*marioSize, 0, 0);
            breakable_block3 = new Block(view, 105*marioSize, 8*marioSize, 0, 0);
            blocks.add(breakable_block0);
            blocks.add(breakable_block1);
            blocks.add(breakable_block2);
            blocks.add(breakable_block3);
        }
        if(level == 3){
            //floors
            floor0 = new Block(view,0, 18*marioSize, 3, 3);
            floor1 = new Block(view,2*screenW-marioSize, 18*marioSize, 3, 3);
            floors.add(floor0);
            floors.add(floor1);

            //Screen 1
            item_block0 = new Block(view, 0*screenW+8*marioSize, 13*marioSize, 1, 0);
            item_block1 = new Block(view, 0*screenW+9*marioSize, 13*marioSize, 1, 0);
            item_block2 = new Block(view, 0*screenW+10*marioSize, 13*marioSize, 1, 2);
            blocks.add(item_block0);
            blocks.add(item_block1);
            blocks.add(item_block2);
            goomba0 = new Enemy(view, 0*screenW+30*marioSize, 17*marioSize, 0);
            goomba1 = new Enemy(view, 0*screenW+32*marioSize, 17*marioSize, 0);
            goomba2 = new Enemy(view, 0*screenW+34*marioSize, 17*marioSize, 0);
            goomba3 = new Enemy(view, 0*screenW+36*marioSize, 17*marioSize, 0);
            enemies.add(goomba0);
            enemies.add(goomba1);
            enemies.add(goomba2);
            enemies.add(goomba3);

            //Screen 2
            breakable_block0 = new Block(view, 1*screenW+5*marioSize, 13*marioSize, 0, 0);
            breakable_block1 = new Block(view, 1*screenW+6*marioSize, 13*marioSize, 0, 0);
            breakable_block2 = new Block(view, 1*screenW+7*marioSize, 13*marioSize, 0, 0);
            breakable_block3 = new Block(view, 1*screenW+12*marioSize, 8*marioSize, 0, 0);
            breakable_block4 = new Block(view, 1*screenW+13*marioSize, 8*marioSize, 0, 0);
            breakable_block5 = new Block(view, 1*screenW+14*marioSize, 8*marioSize, 0, 0);
            breakable_block6 = new Block(view, 1*screenW+21*marioSize, 13*marioSize, 0, 0);
            breakable_block7 = new Block(view, 1*screenW+22*marioSize, 13*marioSize, 0, 0);
            breakable_block8 = new Block(view, 1*screenW+23*marioSize, 13*marioSize, 0, 0);
            breakable_block9 = new Block(view, 1*screenW+28*marioSize, 8*marioSize, 0, 0);
            breakable_block10 = new Block(view, 1*screenW+29*marioSize, 8*marioSize, 0, 0);
            breakable_block11 = new Block(view, 1*screenW+30*marioSize, 8*marioSize, 0, 0);
            blocks.add(breakable_block0);
            blocks.add(breakable_block1);
            blocks.add(breakable_block2);
            blocks.add(breakable_block3);
            blocks.add(breakable_block4);
            blocks.add(breakable_block5);
            blocks.add(breakable_block6);
            blocks.add(breakable_block7);
            blocks.add(breakable_block8);
            blocks.add(breakable_block9);
            blocks.add(breakable_block10);
            blocks.add(breakable_block11);
            koopa0 = new Enemy(view, 1*screenW+7*marioSize, 12*marioSize, 1);
            koopa1 = new Enemy(view, 1*screenW+14*marioSize, 7*marioSize, 1);
            koopa2 = new Enemy(view, 1*screenW+23*marioSize, 12*marioSize, 1);
            koopa3 = new Enemy(view, 1*screenW+30*marioSize, 7*marioSize, 1);
            enemies.add(koopa0);
            enemies.add(koopa1);
            enemies.add(koopa2);
            enemies.add(koopa3);
            coin0 = new Item(view, 1*screenW+6*marioSize, 12*marioSize, 0);
            coin1 = new Item(view, 1*screenW+13*marioSize, 7*marioSize, 0);
            coin2 = new Item(view, 1*screenW+22*marioSize, 12*marioSize, 0);
            coin3 = new Item(view, 1*screenW+29*marioSize, 7*marioSize, 0);
            items.add(coin0);
            items.add(coin1);
            items.add(coin2);
            items.add(coin3);

            //Screen 3
            goomba4 = new Enemy(view, 2*screenW+12*marioSize, 17*marioSize, 1);
            goomba5 = new Enemy(view, 2*screenW+16*marioSize, 17*marioSize, 1);
            goomba6 = new Enemy(view, 2*screenW+20*marioSize, 17*marioSize, 1);
            enemies.add(goomba4);
            enemies.add(goomba5);
            enemies.add(goomba6);
            koopa4 = new Enemy(view, 2*screenW+10*marioSize, 17*marioSize, 1);
            koopa5 = new Enemy(view, 2*screenW+14*marioSize, 17*marioSize, 1);
            koopa6 = new Enemy(view, 2*screenW+18*marioSize, 17*marioSize, 1);
            enemies.add(koopa4);
            enemies.add(koopa5);
            enemies.add(koopa6);
            coin4 = new Item(view, 2*screenW+20*marioSize, 11*marioSize, 0);
            coin5 = new Item(view, 2*screenW+21*marioSize, 11*marioSize, 0);
            coin6 = new Item(view, 2*screenW+22*marioSize, 11*marioSize, 0);
            coin7 = new Item(view, 2*screenW+23*marioSize, 11*marioSize, 0);
            coin8 = new Item(view, 2*screenW+24*marioSize, 11*marioSize, 0);
            coin9 = new Item(view, 2*screenW+25*marioSize, 11*marioSize, 0);
            coin10 = new Item(view, 2*screenW+20*marioSize, 10*marioSize, 0);
            coin11 = new Item(view, 2*screenW+21*marioSize, 10*marioSize, 0);
            coin12 = new Item(view, 2*screenW+22*marioSize, 10*marioSize, 0);
            coin13 = new Item(view, 2*screenW+23*marioSize, 10*marioSize, 0);
            coin14 = new Item(view, 2*screenW+24*marioSize, 10*marioSize, 0);
            coin15 = new Item(view, 2*screenW+25*marioSize, 10*marioSize, 0);
            items.add(coin4);
            items.add(coin5);
            items.add(coin6);
            items.add(coin7);
            items.add(coin8);
            items.add(coin9);
            items.add(coin10);
            items.add(coin11);
            items.add(coin12);
            items.add(coin13);
            items.add(coin14);
            items.add(coin15);

        }
        floor0 = null;
        floor1 = null;
        floor2 = null;

        breakable_block0 = null;
        breakable_block1 = null;
        breakable_block2 = null;
        breakable_block3 = null;
        breakable_block4 = null;
        breakable_block5 = null;
        breakable_block6 = null;
        breakable_block7 = null;
        breakable_block8 = null;
        breakable_block9 = null;
        breakable_block10 = null;
        breakable_block11 = null;

        item_block0 = null;
        item_block1 = null;
        item_block2 = null;

        coin0 = null;
        coin1 = null;
        coin2 = null;
        coin3 = null;
        coin4 = null;
        coin5 = null;
        coin6 = null;
        coin7 = null;
        coin8 = null;
        coin9 = null;
        coin10 = null;
        coin11 = null;
        coin12 = null;
        coin13 = null;
        coin14 = null;
        coin15 = null;

        goomba0 = null;
        goomba1 = null;
        goomba2 = null;
        goomba3 = null;
        goomba4 = null;
        goomba5 = null;
        goomba6 = null;

        koopa0 = null;
        koopa1 = null;
        koopa2 = null;
        koopa3 = null;
        koopa4 = null;
        koopa5 = null;
        koopa6 = null;
    }

    public void tick (Canvas canvas){
        //Draw Objects
        if(!enemies.isEmpty()) {
            for (int i = 0; i < enemies.size(); i++) {
                enemies.get(i).tick(canvas);
            }
        }
        if(!items.isEmpty()) {
            for (int i = 0; i < items.size(); i++) {
                items.get(i).tick(canvas);
            }
        }
        if(!blocks.isEmpty()) {
            for (int i = 0; i < blocks.size(); i++) {
                blocks.get(i).tick(canvas);
                if(blocks.get(i).blockItem != null){
                    blocks.get(i).blockItem.tick(canvas);
                }
            }
        }

        if(!floors.isEmpty()) {
            for (int i = 0; i < floors.size(); i++) {
                floors.get(i).tick(canvas);
            }
        }
    }

    public void removeObjects(){
        //Remove object
        if(!enemies.isEmpty()) {
            for (int i = 0; i < enemies.size(); i++) {
                if (enemies.get(i).mAlpha <= 0) {
                    enemies.remove(i);
                }
            }
        }
        if(!items.isEmpty()) {
            for (int i = 0; i < items.size(); i++) {
                if (items.get(i).mAlpha <= 0) {
                    items.remove(i);
                }
            }
        }
        if(!blocks.isEmpty()) {
            for (int i = 0; i < blocks.size(); i++) {
                if (blocks.get(i).mAlpha <= 0) {
                    blocks.remove(i);
                }
                if(blocks.get(i).blockItem != null && blocks.get(i).blockItem.mAlpha <= 0){
                    blocks.get(i).blockItem = null;
                }
            }
        }
    }
}
