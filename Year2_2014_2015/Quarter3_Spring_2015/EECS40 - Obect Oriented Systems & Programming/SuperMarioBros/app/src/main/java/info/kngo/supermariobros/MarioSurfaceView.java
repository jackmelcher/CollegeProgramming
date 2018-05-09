package info.kngo.supermariobros;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.Typeface;
import android.os.CountDownTimer;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.ArrayList;

/**
 * Created by Kevin on 5/11/2015.
 */
public class MarioSurfaceView extends SurfaceView implements SurfaceHolder.Callback, TimeConscious {

    private MarioRenderThread renderThread;

    //Game Object Variables

    //Screen Width and Height
    private int screenW, screenH;    
    
    //Mario Object and variables
    public Mario mario;

    private int jumpVel = -35;
    private int accelX = 3;
    private final int enemyVelX = -3;

    private int marioSize;
    private Fireball fireball;
    public CountDownTimer cdt;

    //Background Objects
    private Background background;
    private Background background2;

    //Flag object
    private Flag flag;

    //Controller buttons
    private ControllerLayout control;

    //start screen
    private Bitmap startScreen;
    private Bitmap start_supermariobros;
    private Bitmap start_selectlevel;
    private Bitmap start_levelone;
    private Bitmap start_leveltwo;
    private Bitmap start_levelthree;

    private Bitmap screen_levelone;
    private Bitmap screen_leveltwo;
    private Bitmap screen_levelthree;
    private Bitmap lives;
    private Bitmap one;
    private Bitmap two;
    private Bitmap three;
    private Bitmap time;
    private Bitmap forty;
    private Bitmap fifty;
    private Bitmap sixty;

    //Boundaries for Start Screen
    Rect dst_startscreen;
    Rect dst_supermariobros;
    Rect dst_selectlevel;
    Rect dst_levelone;
    Rect dst_leveltwo;
    Rect dst_levelthree;
    Rect dst_lives;
    Rect dst_one;
    Rect dst_two;
    Rect dst_three;
    Rect dst_time;
    Rect dst_forty;
    Rect dst_fifty;
    Rect dst_sixty;

    //Game state
    private boolean gameState = false;
    private boolean timeSelected = false;

    //Game score, time, coins, lives, level..
    public int gameScore = 0;
    public int countdownTimer = 0;
    public int marioLives = 3;
    public int coinCount = 0;
    private int level = 0;
    int reset_counter = 100;
    private int timer = 60;

    //Test Objects
    private LevelFactory levelFactory;


    public MarioSurfaceView(Context context){
        super(context);
        //Waits until program shows up on screen
        getHolder().addCallback(this);
        //Enable touch events on screen
        setFocusable(true);
    }

    //After appearing on screen, begin thread and initialize variables
    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        //Screen Width
        screenW = getWidth();
        //Screen Height
        screenH = getHeight();
        //Standard size of mario proportional to screen
        marioSize = screenH/20;

        // Launch animator thread .
        renderThread = new MarioRenderThread ( this ) ;
        renderThread . start() ;

        //Start screen
        BitmapFactory. Options options = new BitmapFactory . Options () ;


        startScreen = BitmapFactory.decodeResource(this.getResources(), R.drawable.startscreen, options) ;
        start_supermariobros = BitmapFactory.decodeResource(this.getResources(), R.drawable.start_supermariobros, options);
        start_selectlevel = BitmapFactory.decodeResource(this.getResources(), R.drawable.start_selectlevel, options);
        start_levelone = BitmapFactory.decodeResource(this.getResources(), R.drawable.start_levelone, options);
        start_leveltwo = BitmapFactory.decodeResource(this.getResources(), R.drawable.start_leveltwo, options);
        start_levelthree = BitmapFactory.decodeResource(this.getResources(), R.drawable.start_levelthree, options);
            lives = BitmapFactory.decodeResource(this.getResources(), R.drawable.lives, options);
            one = BitmapFactory.decodeResource(this.getResources(), R.drawable.one, options);
            two = BitmapFactory.decodeResource(this.getResources(), R.drawable.two, options);
            three = BitmapFactory.decodeResource(this.getResources(), R.drawable.three, options);
            time = BitmapFactory.decodeResource(this.getResources(), R.drawable.time, options);
            forty = BitmapFactory.decodeResource(this.getResources(), R.drawable.forty, options);
            fifty = BitmapFactory.decodeResource(this.getResources(), R.drawable.fifty, options);
            sixty = BitmapFactory.decodeResource(this.getResources(), R.drawable.sixty, options);

        // Create game objects (These objects will be stored in the Surface View)
        mario = new Mario(this, marioSize, 10*marioSize);
        background = new Background(this, 0, 0, screenW, screenH,0);
        background2 = new Background(this, screenW, 0, 2*screenW, screenH,1);
        flag = new Flag(this, 3*screenW - 2*marioSize, 0, 3*screenW, screenH);
        control = new ControllerLayout(this);
        cdt = new CountDownTimer(timer*1000, 1000) {
            @Override
            public void onTick(long millisUntilFinished) {
                countdownTimer = (int)millisUntilFinished/ 1000;
            }

            @Override
            public void onFinish() {

                mario.dead = true;
                mario.mVelY = -50;
            }
        };


    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
        // Respond to surface changes , e . g . , aspect ratio changes .
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
        // The cleanest way to stop a thread is by interrupting it .
        // MarioRenderThread regularly checks its interrupt flag .
        renderThread.interrupt() ;
    }

    @Override
    public boolean onTouchEvent(MotionEvent e){
        //Mario's controls and movement settings
        float x1, y1;
        int activePointer;
        int pointerIndex;

        int newPointerIndex;
        int newPointer;
        float x2;
        float y2;

        switch(e.getActionMasked()){
            case MotionEvent.ACTION_DOWN:
                activePointer = e.getPointerId(0);
                pointerIndex = e.findPointerIndex(activePointer);
                x1 = e.getX(pointerIndex);
                y1 = e.getY(pointerIndex);

                //Level one selection
                if (dst_levelone.contains((int) x1, (int) y1)) {
                    level = 1;
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                    gameState = true;
                }
                //Level two selection
                if (dst_leveltwo.contains((int) x1, (int) y1)) {
                    level = 2;
                    //Test spawns
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                    gameState = true;
                }
                //Level three selection
                if (dst_levelthree.contains((int) x1, (int) y1)) {
                    level = 3;
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                    gameState = true;
                }
                //Select number of Lives
                if (dst_one.contains((int) x1, (int) y1)) {
                    marioLives = 1;
                }
                if (dst_two.contains((int) x1, (int) y1)) {
                    marioLives = 2;
                }
                if (dst_three.contains((int) x1, (int) y1)) {
                    marioLives = 3;
                }

                if(dst_forty.contains((int) x1, (int) y1) && !timeSelected) {
                    timer = 40;
                    cdt = new CountDownTimer(timer * 1000, 1000) {
                        @Override
                        public void onTick(long millisUntilFinished) {
                            countdownTimer = (int) millisUntilFinished / 1000;
                        }

                        @Override
                        public void onFinish() {

                            mario.dead = true;
                            mario.mVelY = -50;
                        }
                    };
                    timeSelected = true;
                }
                if(dst_fifty.contains((int) x1, (int) y1) && !timeSelected) {
                    timer = 50;
                    cdt = new CountDownTimer(timer * 1000, 1000) {
                        @Override
                        public void onTick(long millisUntilFinished) {
                            countdownTimer = (int) millisUntilFinished / 1000;
                        }

                        @Override
                        public void onFinish() {

                            mario.dead = true;
                            mario.mVelY = -50;
                        }
                    };
                    timeSelected = true;
                }
                if(dst_sixty.contains((int) x1, (int) y1) && !timeSelected) {
                    timer = 60;
                    cdt = new CountDownTimer(timer * 1000, 1000) {
                        @Override
                        public void onTick(long millisUntilFinished) {
                            countdownTimer = (int) millisUntilFinished / 1000;
                        }

                        @Override
                        public void onFinish() {

                            mario.dead = true;
                            mario.mVelY = -50;
                        }
                    };
                    timeSelected = true;
                }


                if(!mario.dead && !flag.finish) {
                    //Move Right
                    if (x1 < 328 && x1 > 200 && y1 < (screenH / 2 + 128) && y1 > screenH / 2 - 128) {
                        mario.mAccelX = accelX;
                        mario.facingRight = true;
                    }
                    //Move Left
                    if (x1 < 200 && x1 > 72 && y1 < (screenH / 2 + 128) && y1 > screenH / 2 - 128) {
                        mario.mAccelX = -accelX;
                        mario.facingRight = false;
                    }

                    //Jump
                    if (control != null && control.dst_a != null && control.dst_a.contains((int) x1, (int) y1)) {
                        if (!mario.jumping) {
                            mario.mVelY = jumpVel;
                            mario.jumping = true;
                        }
                    }

                    //Shoot Fireball
                    if (control != null && control.dst_b != null && control.dst_b.contains((int) x1, (int) y1) && mario.fireflower) {
                        if(fireball == null) {
                            if (mario.facingRight) {
                                fireball = new Fireball(this, mario.mX2, mario.mY1 + marioSize/2, mario.mX2 + marioSize, mario.mY2 - marioSize/2);
                            } else if (!mario.facingRight) {
                                fireball = new Fireball(this, mario.mX1 - marioSize, mario.mY1 + marioSize/2, mario.mX1, mario.mY2 - marioSize/2);
                            }
                        }
                    }
                }
                break;

            case MotionEvent.ACTION_POINTER_DOWN:
                newPointerIndex = e.getActionIndex();
                newPointer = e.getPointerId(newPointerIndex);
                x2 = e.getX(newPointer);
                y2 = e.getY(newPointer);


                if(!mario.dead && !flag.finish) {
                    //Move Right
                    if (x2 < 328 && x2 > 200 && y2 < (screenH / 2 + 128) && y2 > screenH / 2 - 128) {
                        mario.mAccelX = accelX;
                        mario.facingRight = true;
                    }
                    //Move Left
                    if (x2 < 200 && x2 > 72 && y2 < (screenH / 2 + 128) && y2 > screenH / 2 - 128) {
                        mario.mAccelX = -accelX;
                        mario.facingRight = false;
                    }
                    //Jump
                    if (control != null && control.dst_a != null && control.dst_a.contains((int) x2, (int) y2)) {
                        if (!mario.jumping) {
                            mario.mVelY = jumpVel;
                            mario.jumping = true;
                        }
                    }
                    //Shoot Fireball
                    if (control != null && control.dst_b != null && control.dst_b.contains((int) x2, (int) y2) && mario.fireflower) {
                        if(fireball == null) {
                            if (mario.facingRight) {
                                fireball = new Fireball(this, mario.mX2, mario.mY1 + marioSize/2, mario.mX2 + marioSize, mario.mY2 - marioSize/2);
                            } else if (!mario.facingRight) {
                                fireball = new Fireball(this, mario.mX1 - marioSize, mario.mY1 + marioSize/2, mario.mX1, mario.mY2 - marioSize/2);
                            }
                        }
                    }
                }
                break;

            case MotionEvent.ACTION_MOVE:
                activePointer = e.getPointerId(0);
                pointerIndex = e.findPointerIndex(activePointer);
                x1 = e.getX(pointerIndex);
                y1 = e.getY(pointerIndex);

                if(!mario.dead && !flag.finish) {
                    //Move Right
                    if (x1 < 328 && x1 > 200 && y1 < (screenH / 2 + 128) && y1 > screenH / 2 - 128) {
                        mario.mAccelX = accelX;
                        mario.facingRight = true;
                    }
                    //Move Left
                    if (x1 < 200 && x1 > 72 && y1 < (screenH / 2 + 128) && y1 > screenH / 2 - 128) {
                        mario.mAccelX = -accelX;
                        mario.facingRight = false;
                    }
                }
                break;

            case MotionEvent.ACTION_UP:
                activePointer = e.getPointerId(0);
                pointerIndex = e.findPointerIndex(activePointer);
                x1 = e.getX(pointerIndex);
                y1 = e.getY(pointerIndex);
                //Idle
                mario.mAccelX = 0;
                mario.mVelX = 0;

                if(!mario.dead) {
                    //Jump
                   if (control != null && control.dst_a != null && control.dst_a.contains((int) x1, (int) y1)) {
                       if(mario.jumping && mario.mVelY < 0){
                           mario.mVelY = -1;
                       }
                    }
                }
                break;
            case MotionEvent.ACTION_POINTER_UP:
                newPointerIndex = e.getActionIndex();
                newPointer = e.getPointerId(newPointerIndex);
                x2 = e.getX(newPointer);
                y2 = e.getY(newPointer);

                if(!mario.dead) {
                    //Jump
                    if (control != null && control.dst_a != null && control.dst_a.contains((int) x2, (int) y2)) {
                        if(mario.jumping && mario.mVelY < 0){
                            mario.mVelY = -1;
                        }
                    }
                }
                break;

        }
        return true;
    }

    @Override
    public void onDraw(Canvas c) {
        super.onDraw(c);
    }

    @Override
    public void tick(Canvas c){

        /**** "Game engine" ****/

        // "Rendering"

        //Start Screen and menu
        if(!gameState){

            //Draw the start screen
            drawStartScreen(c);

            //Pre-Level Screens
            //dst = new Rect(0, 0, screenW, screenH);
            //c.drawBitmap(screen_levelone, null, dst, paint);
            //c.drawBitmap(screen_leveltwo, null, dst, paint);
            //c.drawBitmap(screen_levelthree, null, dst, paint);

        }

        //Draw game objects
        if(gameState) {


            //Remove game objects
            levelFactory.removeObjects();

            //All Game objects scroll left as Mario moves right
            scrollGameObjects();

            //Draw background
            if (background != null) {
                background.tick(c);
            }
            //Draw background
            if (background2 != null) {
                background2.tick(c);
            }
            //Draw Mario
            if (mario != null) {
                mario.tick(c);
            }
            //Draw Controller Buttons
            if (control != null) {
                control.tick(c);
            }
            //Draw fireballs
            if (fireball != null) {
                fireball.tick(c);
            }
            //Draw Flag
            if(flag != null) {
                flag.tick(c);
            }
            //Draw Level Factory
            levelFactory.tick(c);
            //Draw game screen elements
            drawGameScreen(c);
        }


        //If mario is not dead, then do these
        if(!mario.dead) {
            //Mario jump detection
            jumpDetection(levelFactory.floors, levelFactory.blocks);

            //Checks surroundings
            if(!levelFactory.floors.isEmpty()) {
                for (int i = 0; i < levelFactory.floors.size(); i++) {
                    mario.environmentCheck(levelFactory.floors.get(i));
                }
            }

            //Mario runs into a block
            if(!levelFactory.blocks.isEmpty()) {
                for (int i = 0; i < levelFactory.blocks.size(); i++) {
                    mario.blockCollisionCheck(levelFactory.blocks.get(i));
                }
            }

            //Fireball collision onto enemy check
            if(!levelFactory.enemies.isEmpty()) {
                for (int i = 0; i < levelFactory.enemies.size(); i++) {
                    fireBallCollision(levelFactory.enemies.get(i));
                }
            }
            //Fireball on floors and blocks check
            if(fireball != null){
                if(fireball.mX1 > screenW || fireball.mX2 < 0) {
                    fireball = null;
                }
                if(!levelFactory.floors.isEmpty()) {
                    for (int i = 0; i < levelFactory.floors.size(); i++) {
                        if (fireball.dst.intersect(levelFactory.floors.get(i).rect_left) || fireball.dst.intersect(levelFactory.floors.get(i).rect_right)) {
                            fireball = null;
                        }
                    }
                }

                if(!levelFactory.blocks.isEmpty()) {
                    for (int i = 0; i < levelFactory.blocks.size(); i++) {
                        if (fireball.dst.intersect(levelFactory.blocks.get(i).rect_left) || fireball.dst.intersect(levelFactory.blocks.get(i).rect_right)) {
                            fireball = null;
                        }
                    }
                }

            }
            //Mario retrieves an item
            if(!levelFactory.items.isEmpty()) {
                for(int i = 0; i < levelFactory.items.size(); i++){
                    mario.itemCollisionCheck(levelFactory.items.get(i));
                }
            }

            if(!levelFactory.blocks.isEmpty()) {
                for(int i = 0; i < levelFactory.blocks.size(); i++){
                    if(levelFactory.blocks.get(i).blockItem != null){
                        mario.itemCollisionCheck(levelFactory.blocks.get(i).blockItem);
                    }
                }
            }

            //Mario stomps onto an enemy
            if(!levelFactory.enemies.isEmpty()) {
                for (int i = 0; i < levelFactory.enemies.size(); i++) {
                    mario.enemyCollisionCheck(levelFactory.enemies.get(i));
                }
            }
            //Mario collides with flag
            mario.flagFinish(flag);

        }

        //If Mario dies, do the following
        else{
            //Restart Level
            //if(marioLives >= 0){restartLevel();}
            //Restart Game
            restartGame();
        }

        //If Mario completes the level
        if(flag.finish) {
            //Restart Level
            //if(marioLives >= 0){restartLevel();}
            //Restart Game
            restartGame();
        }
    }



    /*********** Methods for the game play *************/


    public void scrollGameObjects(){
        if(mario.mX2 >= screenW/2 && mario.mVelX > 0){
            background.mVelX = -mario.mVelX;
            background2.mVelX = -mario.mVelX;
            flag.mVelX = -mario.mVelX;

            if(!levelFactory.floors.isEmpty()){
                for (int i = 0; i < levelFactory.floors.size(); i++) {
                    levelFactory.floors.get(i).mVelX = -mario.mVelX;
                }
            }

            if(!levelFactory.blocks.isEmpty()){
                for (int i = 0; i < levelFactory.blocks.size(); i++) {
                    levelFactory.blocks.get(i).mVelX = -mario.mVelX;
                    if(levelFactory.blocks.get(i).blockItem != null) {
                        levelFactory.blocks.get(i).blockItem.mVelX = -mario.mVelX;
                    }
                }
            }

            if(!levelFactory.enemies.isEmpty()){
                for (int i = 0; i < levelFactory.enemies.size(); i++) {
                    if(levelFactory.enemies.get(i).mX1 < screenW && levelFactory.enemies.get(i).mY2 > 16*marioSize) {
                            levelFactory.enemies.get(i).mVelX = -mario.mVelX + enemyVelX;
                    }
                    else{levelFactory.enemies.get(i).mVelX = -mario.mVelX;}
                }
            }
            if(!levelFactory.items.isEmpty()){
                for (int i = 0; i < levelFactory.items.size(); i++) {
                    levelFactory.items.get(i).mVelX = -mario.mVelX;
                }
            }
            if(fireball != null){
                if(fireball.mVelX >= 0){
                    fireball.mVelX = -mario.mVelX + fireball.fireballVelX;
                }
                else{
                    fireball.mVelX = -mario.mVelX - fireball.fireballVelX;
                }
            }
            //Increment Game Score
            gameScore++;

        }
        else{
            background.mVelX = 0;
            background2.mVelX = 0;
            flag.mVelX = 0;

            if(!levelFactory.floors.isEmpty()){
                for (int i = 0; i < levelFactory.floors.size(); i++) {
                    levelFactory.floors.get(i).mVelX = 0;
                }
            }

            if(!levelFactory.blocks.isEmpty()){
                for (int i = 0; i < levelFactory.blocks.size(); i++) {
                    levelFactory.blocks.get(i).mVelX = 0;
                    if(levelFactory.blocks.get(i).blockItem != null) {
                        levelFactory.blocks.get(i).blockItem.mVelX = 0;
                    }
                }
            }

            if(!levelFactory.enemies.isEmpty()){
                for (int i = 0; i < levelFactory.enemies.size(); i++) {
                    if(levelFactory.enemies.get(i).mX1 < screenW && levelFactory.enemies.get(i).mY2 > 16*marioSize) {
                        levelFactory.enemies.get(i).mVelX = enemyVelX;
                    }
                    else{levelFactory.enemies.get(i).mVelX = 0;}
                }
            }
            if(!levelFactory.items.isEmpty()){
                for (int i = 0; i < levelFactory.items.size(); i++) {
                    levelFactory.items.get(i).mVelX = 0;
                }
            }
            if(fireball != null) {
                if (fireball.mVelX >= 0) {
                    fireball.mVelX = fireball.fireballVelX;
                } else {
                    fireball.mVelX = -fireball.fireballVelX;
                }
            }
        }

    }

    //Jump Detection
    public void jumpDetection(ArrayList<Block> floors, ArrayList<Block> blocks){
        boolean jumpCheck = false;

        if(!levelFactory.floors.isEmpty()){
            for (int i = 0; i < levelFactory.floors.size(); i++) {
                if((floors.get(i) != null && mario.rect_bottom.intersect(floors.get(i).rect_top))){
                    mario.jumping = false;
                    jumpCheck = true;
                    break;
                }
                else{mario.jumping = true;}
            }
        }
        if(!levelFactory.blocks.isEmpty() && !jumpCheck) {
            for (int i = 0; i < levelFactory.blocks.size(); i++) {
                if((blocks.get(i) != null && mario.rect_bottom.intersect(blocks.get(i).rect_top))){
                    mario.jumping = false;
                    break;
                }
                else{mario.jumping = true;}
            }
        }
    }

    //Fireball collision
    public void fireBallCollision(Enemy enemy){
        //Fireball collides with an enemy
        if(enemy != null && fireball != null && fireball.dst.intersect(enemy.dst)){
            enemy.dead = true;
            fireball = null;
            enemy.mAlpha = 0;
            gameScore += 100;
        }
    }

    //Draw the start screen
    public void drawStartScreen(Canvas c){

        //Paint object for texts
        Paint paint = new Paint();
        BitmapFactory. Options options = new BitmapFactory . Options () ;

        //Boundaries for start screen
        dst_startscreen = new Rect(0, 0, screenW, screenH); // Where to draw .
        c.drawBitmap(startScreen, null, dst_startscreen, paint);

        dst_supermariobros = new Rect(marioSize, 0 , getWidth() - marioSize, 4*marioSize);
        c.drawBitmap(start_supermariobros, null, dst_supermariobros, paint);

        dst_selectlevel = new Rect(getWidth()/4, 5*marioSize, 3*getWidth()/4, 7*marioSize);
        c.drawBitmap(start_selectlevel, null, dst_selectlevel, paint);

        dst_levelone = new Rect(2*getWidth()/5, 8*marioSize, 3*getWidth()/5, 10*marioSize);
        c.drawBitmap(start_levelone, null, dst_levelone, paint);

        dst_leveltwo = new Rect(2*getWidth()/5, 11*marioSize, 3*getWidth()/5, 13*marioSize);
        c.drawBitmap(start_leveltwo, null, dst_leveltwo, paint);

        dst_levelthree = new Rect(2*getWidth()/5, 14*marioSize, 3*getWidth()/5, 16*marioSize);
        c.drawBitmap(start_levelthree, null, dst_levelthree, paint);

        dst_lives = new Rect(marioSize, 9*marioSize, 7*marioSize, 12*marioSize);
        c.drawBitmap(lives, null, dst_lives, paint);

        dst_one = new Rect(marioSize, 12*marioSize, 3*marioSize, 14*marioSize);
        c.drawBitmap(one, null, dst_one, paint);

        dst_two = new Rect(3*marioSize, 12*marioSize, 5*marioSize, 14*marioSize);
        c.drawBitmap(two, null, dst_two, paint);

        dst_three = new Rect(5*marioSize, 12*marioSize, 7*marioSize, 14*marioSize);
        c.drawBitmap(three, null, dst_three, paint);

        dst_time = new Rect(31*marioSize, 9*marioSize, 36*marioSize, 12*marioSize);
        c.drawBitmap(time, null, dst_time, paint);

        dst_forty = new Rect(29*marioSize, 12*marioSize, 32* marioSize, 14*marioSize);
        c.drawBitmap(forty, null, dst_forty, paint);

        dst_fifty = new Rect(32*marioSize, 12*marioSize, 35* marioSize, 14*marioSize);
        c.drawBitmap(fifty, null, dst_fifty, paint);

        dst_sixty = new Rect(35*marioSize, 12*marioSize, 38* marioSize, 14*marioSize);
        c.drawBitmap(sixty, null, dst_sixty, paint);
    }


    //Draw game screen elements
    public void drawGameScreen(Canvas c){
        //Paint object for texts
        Paint paint = new Paint();

        //Set text details
        paint.setTypeface(Typeface.create(Typeface.DEFAULT, Typeface.BOLD));
        paint.setTextSize(2*marioSize/3);
        paint.setColor(Color.WHITE);

        //Draw score text
        c.drawText("MARIO", screenW / 20, marioSize, paint);
        NumberFormat formatter = new DecimalFormat("000000");
        c.drawText("" +formatter.format(gameScore), screenW / 20, 5*marioSize/3, paint);

        //Draw Time text
        c.drawText("TIME", 17*screenW/20, marioSize, paint);
        formatter = new DecimalFormat("000");
        c.drawText("  "+formatter.format(countdownTimer), 17*screenW/20, 5*marioSize/3, paint);

        //Draw world level text
        c.drawText("WORLD", 13*screenW/20, marioSize, paint);
        c.drawText("LEVEL "+level, 13*screenW/20, 5*marioSize/3, paint);

        //Draw lives text
        c.drawText("LIVES x "+marioLives, 5*screenW/20, marioSize, paint);
        formatter = new DecimalFormat("00");
        c.drawText("COINS x "+formatter.format(coinCount), 5*screenW/20, 5*marioSize/3, paint);

    }
    
    //Restart the game if you have no lives left
    public void restartGame(){
        reset_counter -= 1;
        if(reset_counter <= 0){
            if(timer > 0 && level != 3 && !mario.dead){
                reset_counter = 100;
                cdt.cancel();
                if(level == 1){
                    level += 1;
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                }
                else if(level == 2){
                    level += 1;
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                }
                //Re-instantiate game objects
                mario = new Mario(this, marioSize, 10 * marioSize);
                background = new Background(this, 0, 0, screenW, screenH, 0);
                background2 = new Background(this, screenW, 0, 2 * screenW, screenH, 1);
                control = new ControllerLayout(this);
                flag = new Flag(this, 3 * screenW - 2 * marioSize, 0, 3 * screenW, screenH);
            }
            else if(marioLives > 0 && mario.dead){
                marioLives -= 1;
                gameScore = 0;
                coinCount = 0;
                reset_counter = 100;
                cdt.cancel();
                if(level == 1){
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                }
                else if(level == 2){
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                }
                else if(level == 3){
                    levelFactory = new LevelFactory(this, level);
                    cdt.start();
                }

                //Re-instantiate game objects
                mario = new Mario(this, marioSize, 10 * marioSize);
                background = new Background(this, 0, 0, screenW, screenH, 0);
                background2 = new Background(this, screenW, 0, 2 * screenW, screenH, 1);
                control = new ControllerLayout(this);
                flag = new Flag(this, 3 * screenW - 2 * marioSize, 0, 3 * screenW, screenH);
            }

            else {
                gameState = false;
                timeSelected = false;
                marioLives = 3;
                gameScore = 0;
                coinCount = 0;
                reset_counter = 100;
                cdt.cancel();

                //Re-instantiate game objects
                mario = new Mario(this, marioSize, 10 * marioSize);
                background = new Background(this, 0, 0, screenW, screenH, 0);
                background2 = new Background(this, screenW, 0, 2 * screenW, screenH, 1);
                control = new ControllerLayout(this);
                flag = new Flag(this, 3 * screenW - 2 * marioSize, 0, 3 * screenW, screenH);
            }
        }
    }
}
