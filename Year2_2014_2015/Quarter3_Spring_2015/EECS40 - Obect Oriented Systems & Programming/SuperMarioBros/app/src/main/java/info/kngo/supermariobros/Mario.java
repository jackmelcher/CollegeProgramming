package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.Rect;
import android.os.CountDownTimer;

/**
 * Created by Jack on 5/11/2015.
 */
public class Mario implements TimeConscious{

    //Object Properties
    private MarioSurfaceView view;

    //Rect Boundary
    public Rect dst;
    public Rect rect_top;
    public Rect rect_bottom;
    public Rect rect_left;
    public Rect rect_right;
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    //Physics
    public int mAccelX;
    public int mAccelY = 2;
    public int mVelY;
    public int mVelX;
    private int maxVelX = 20;
    private int maxFallVelY = 20;

    //Bitmaps
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmaps[];
    private int marioSize;

    //Other variables
    int invincible = 5;

    //Booleans
    boolean facingRight = true;
    boolean jumping = true;
    boolean dead = false;
    boolean mushroom = false;
    boolean fireflower = false;
    boolean normalState = true;

    //Constructor
    public Mario(MarioSurfaceView view, int x1, int y1) {
        this.view = view;
        this.marioSize = view.getHeight()/20;
        this.mX1 = x1;
        this.mX2 = x1 + marioSize;
        this.mY1 = y1;
        this.mY2 = y1 + marioSize;

        Bitmap[] bitmaps = {
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_idle, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_run, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_jump, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_super_idle, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_super_run, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_super_jump, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_fire_idle, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_fire_run, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_fire_jump, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mario_dead, options),
        };
        this.bitmaps = bitmaps;
    }

    public int getX1(){return mX1;}
    public int getX2(){return mX2;}
    public int getY1(){return mY1;}
    public int getY2(){return mY2;}

    @Override
    public void tick(Canvas canvas) {
        dst = new Rect (getX1(), getY1(), getX2(), getY2()) ; // Where to draw .
        rect_top = new Rect(getX1(), getY1()-marioSize/4, getX2(), getY1() + (getY2()-getY1())/2);
        rect_bottom = new Rect(getX1(), getY1() + marioSize/4, getX2(), getY2()+ marioSize/4);
        rect_left = new Rect(getX1(), getY1()+marioSize/4, getX2()-marioSize/2, getY2());
        rect_right = new Rect(getX1()+marioSize/2, getY1()+marioSize/4, getX2(), getY2());

        draw(canvas);
    }

    //Draws Mario
    public void draw(Canvas c){
        Paint paint = new Paint();

        Rect dst = new Rect (getX1(), getY1(), getX2(), getY2()) ; // Where to draw .

        if(!dead) {
            if (normalState){
                //Jump
                if (jumping) {
                    //Mario faces right after stopping
                    if (facingRight) {
                        c.drawBitmap(bitmaps[2], null, dst, paint);
                    }
                    //Mario faces left after stopping
                    else{
                        c.drawBitmap(flipImage(bitmaps[2]), null, dst, paint);
                    }
                }
                //Idle
                else if (mVelX == 0) {

                    //Mario faces right after stopping
                    if (facingRight) {
                        c.drawBitmap(bitmaps[0], null, dst, paint);
                    }
                    //Mario faces left after stopping
                    else{
                        c.drawBitmap(flipImage(bitmaps[0]), null, dst, paint);
                    }
                }
                //Run to right
                else if (mVelX > 0) {
                    c.drawBitmap(bitmaps[1], null, dst, paint);
                    facingRight = true;
                }
                //Run to left
                else if (mVelX < 0) {
                    c.drawBitmap(flipImage(bitmaps[1]), null, dst, paint);
                    facingRight = false;
                }
            }
            if (mushroom){

                //Increase size of mario due to item
                dst = new Rect(mX1, mY1 - marioSize/4, mX2, mY2);

                //Jump
                if (jumping) {
                    //Mario faces right after jumping
                    if (facingRight) {
                        c.drawBitmap(bitmaps[5], null, dst, paint);
                    }
                    //Mario faces left after jumping
                    else{
                        c.drawBitmap(flipImage(bitmaps[5]), null, dst, paint);
                    }
                }
                //Idle
                else if (mVelX == 0) {
                    //Mario faces right after stopping
                    if (facingRight) {
                        c.drawBitmap(bitmaps[3], null, dst, paint);
                    }
                    //Mario faces left after stopping
                    else{
                        c.drawBitmap(flipImage(bitmaps[3]), null, dst, paint);
                    }
                }
                //Run to right
                else if (mVelX > 0) {
                    c.drawBitmap(bitmaps[4], null, dst, paint);
                    facingRight = true;
                }
                //Run to left
                else if (mVelX < 0) {
                    c.drawBitmap(flipImage(bitmaps[4]), null, dst, paint);
                    facingRight = false;
                }
            }
            if (fireflower){

                //Increase size of mario due to item
                dst = new Rect(mX1, mY1 - marioSize/4, mX2, mY2);

                //Jump
                if (jumping) {
                    //Mario faces right after jumping
                    if (facingRight) {
                        c.drawBitmap(bitmaps[8], null, dst, paint);
                    }
                    //Mario faces left after jumping
                    else{
                        c.drawBitmap(flipImage(bitmaps[8]), null, dst, paint);
                    }
                }
                //Idle
                else if (mVelX == 0) {
                    //Mario faces right after stopping
                    if (facingRight) {
                        c.drawBitmap(bitmaps[6], null, dst, paint);
                    }
                    //Mario faces left after stopping
                    else{
                        c.drawBitmap(flipImage(bitmaps[6]), null, dst, paint);
                    }
                }
                //Run to right
                else if (mVelX > 0) {
                    c.drawBitmap(bitmaps[7], null, dst, paint);
                    facingRight = true;
                }
                //Run to left
                else if (mVelX < 0) {
                    c.drawBitmap(flipImage(bitmaps[7]), null, dst, paint);
                    facingRight = false;
                }
            }
        }
        else{
            //Dead
            c.drawBitmap(bitmaps[9], null, dst, paint);
            maxVelX = 0;
        }

        this.stepCoordinates();
    }

    //physics of Mario
    public void stepCoordinates() {
        int maxX = view.getWidth();

        //Limit the falling speed
        if(mVelY > maxFallVelY){
            mVelY = maxFallVelY;
        }
        //Limit the VelX
        if (mVelX > maxVelX) {
            mVelX = maxVelX;
        }
        if (mVelX < -maxVelX) {
            mVelX = -maxVelX;
        }
        //Bound to inside left and right sides of screen
        if(mX2 > maxX/2){
            mX1 = maxX/2 - marioSize;
            mX2 = maxX/2;
        }
        if(mX1 < 0){
            mX1 = 0;
            mX2 = marioSize;
            mVelX = 0;
        }

        //Accelerate mario
        mVelX += mAccelX;
        mVelY += mAccelY;

        //Jump
        mY1 += mVelY;
        mY2 += mVelY;

        //Move Left/Right
        mX1 += mVelX;
        mX2 += mVelX;
    }

    public void enemyCollisionCheck(Enemy enemy){
        //Mario jumps onto this enemy
        if (enemy != null && rect_bottom.intersect(enemy.rect_top)) {
            enemy.dead = true;
            enemy.mAlpha = 0;
            mVelY = -marioSize / 3;
            view.gameScore += 100;
        }
        //Mario is hit from left side from enemy
        if(enemy != null) {
            if (mY2 > enemy.mY1 && mX2 > enemy.mX1 && mX2 < enemy.mX2 && !enemy.dead) {
                dead = true;
                mVelY = -50;
                view.cdt.cancel();
            }
            //Mario is hit from right side from enemy
            if (mY2 > enemy.mY1 && mX1 < enemy.mX2 && mX1 > enemy.mX1 && !enemy.dead) {
                dead = true;
                mVelY = -50;
                view.cdt.cancel();
            }
        }
    }

    public void environmentCheck(Block floor){
        //Detect touching floor below
        if(mY2 >= floor.mY1 && mX1 >= floor.mX1 && mX2 <= floor.mX2){
            if(normalState) {mY1 = floor.mY1 - marioSize;}
            else if(mushroom || fireflower){mY1 = floor.mY1 - 2*marioSize;}
            mY2 = floor.mY1;
        }
        //Dying from a pitfall
        if (mY2 >= view.getHeight()) {
            dead = true;
            mVelY = -50;
            view.cdt.cancel();
        }
    }

    public void blockCollisionCheck(Block block){
        if(block != null) {
            //Mario hits block from underneath
            if (rect_top.intersect(block.rect_bottom) && mVelY <= 0) {
                if (block.block_type == 0 && (mushroom || fireflower)) {
                    block.mAlpha = 0;
                    view.gameScore += 50;
                }
                if(block.block_type == 1 && !block.emptyBlock){
                    //Spawn an item
                    block.emptyBlock = true;
                    block.blockItem = new Item(view, block.mX1, block.mY1 - marioSize, block.item_type);
                }
                mVelY = 5;
            }
            //Mario runs into a block on the right
            if (rect_right.intersect(block.rect_left)) {
                mX1 = block.mX1 - marioSize ;
                mX2 = block.mX1 ;
            }
            //Mario runs into a block on the left
            if (rect_left.intersect(block.rect_right)) {
                mX1 = block.mX2 ;
                mX2 = block.mX2 + marioSize ;
            }

            //Mario ontop of the block
            if (mY2 >= block.mY1 && mY1 < block.mY1 && ((mX2 > block.mX1 && mX1 < block.mX1 )|| (mX1 < block.mX2 && mX2 > block.mX2))) {
                if(normalState) {
                    mY1 = block.mY1 - marioSize;
                }
                else if(mushroom || fireflower){
                    mY1 = block.mY1 - 2*marioSize;
                }
                mY2 = block.mY1;
                mVelY = 0;
            }
        }
    }

    public void jumpDetection(Block floor, Block block){

        if((floor != null && rect_bottom.intersect(floor.rect_top)) || (block != null && rect_bottom.intersect(block.rect_top))){
            jumping = false;
        }
        else{jumping = true;}

    }


    public void itemCollisionCheck(Item item){
        if(item != null && dst.intersect(item.dst)){
            //Mario retrieves a fireflower
            if(item.item_type == 2) {
                normalState = false;
                mushroom = false;
                fireflower = true;
                mY1 += -marioSize;
                item.mAlpha = 0;
                view.gameScore += 1000;
            }
            //Mario retrieves a mushroom
            if(item.item_type == 1){
                if(!fireflower) {
                    normalState = false;
                    mushroom = true;
                    mY1 += -marioSize;
                    item.mAlpha = 0;
                    view.gameScore += 1000;
                }
                else{
                    item.mAlpha = 0;
                    view.gameScore += 1000;
                }
            }
            //Mario retrieves a coin
            if(item.item_type == 0){
                view.coinCount += 1;
                item.mAlpha = 0;
                view.gameScore += 200;
                if(view.coinCount == 100){
                    view.marioLives += 1;
                    view.coinCount = 0;
                }
            }
        }
    }

    //Mario collides with flag
    public void flagFinish(Flag flag) {
        if (dst.intersect(flag.dst)) {
            mVelX = 0;
            mVelY = 0;
            view.cdt.cancel();
            flag.finish = true;
            mX1 = flag.mX1 - marioSize / 2;
            mX2 = flag.mX1 + marioSize / 2;
            mVelY = 8;
        }
    }

    //Flip an image
    public Bitmap flipImage(Bitmap src) {
        // create new matrix for transformation
        Matrix matrix = new Matrix();
        //Flips the image
        matrix.preScale(-1.0f, 1.0f);
        // return transformed image
        return Bitmap.createBitmap(src, 0, 0, src.getWidth(), src.getHeight(), matrix, true);
    }

}
