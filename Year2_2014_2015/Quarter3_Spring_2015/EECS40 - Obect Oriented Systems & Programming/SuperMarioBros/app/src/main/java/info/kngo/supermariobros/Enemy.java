package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Kevin on 5/11/2015.
 */
public class Enemy implements TimeConscious{
    //Object Properties
    private MarioSurfaceView view;
    private int enemySize;
    private int enemy_type;
    public int mAlpha = 255;

    //Rect Boundary
    public Rect rect_top;
    public Rect rect_bottom;
    public Rect rect_left;
    public Rect rect_right;
    public Rect dst;
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    //Physics
    public double mVelY = 5;
    public double mVelX = 3;

    //Bitmaps
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmaps[];

    //Booleans
    boolean dead = false;

    //Constructor
    public Enemy(MarioSurfaceView view, int x1, int y1, int enemy_type){
        this.view = view;
        this.enemySize = view.getHeight()/20;
        this.mX1 = x1;
        this.mX2 = x1 + enemySize;
        this.mY1 = y1;
        this.mY2 = y1 + enemySize;
        Bitmap[] bitmaps = {
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.goomba, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.goomba_dead, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.koopa, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.koopa_shell, options),
        };
        this.bitmaps = bitmaps;
        this.enemy_type = enemy_type;
    }

    public int getX1(){return mX1;}
    public int getX2(){return mX2;}
    public int getY1(){return mY1;}
    public int getY2(){return mY2;}

    @Override
    public void tick(Canvas canvas) {
        rect_top = new Rect(getX1(), getY1() - enemySize/4, getX2(), (getY2()+getY1())/2);
        rect_left = new Rect(getX1() - enemySize/4, getY1(), getX2(), getY2());
        rect_right = new Rect(getX1(), getY1(), getX2() + enemySize/4, getY2());
        draw(canvas);
    }
    //Draws Enemy
    public void draw(Canvas c){
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        paint.setAlpha(mAlpha);

        //Goomba
        if(enemy_type ==0) {
            if (!dead) {
                dst = new Rect(getX1(), getY1(), getX2(), getY2()); // Where to draw .
                c.drawBitmap(bitmaps[0], null, dst, paint);
            }
            else {
                dst = new Rect(mX1, mY1 + enemySize / 2, mX2, mY2);
                c.drawBitmap(bitmaps[1], null, dst, paint);
            }
        }
        //Koopa
        if(enemy_type == 1){
            if (!dead) {
                dst = new Rect(getX1(), getY1(), getX2(), getY2()); // Where to draw .
                c.drawBitmap(flipImage(bitmaps[2]), null, dst, paint);
            }
            else {
                dst = new Rect(mX1, mY1 + enemySize, mX2, mY2);
                c.drawBitmap(bitmaps[3], null, dst, paint);
            }
        }
        this.stepCoordinates();
    }

    //AI of the Enemy
    public void stepCoordinates() {

        //Move
        mX1 += mVelX;
        mX2 += mVelX;

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

