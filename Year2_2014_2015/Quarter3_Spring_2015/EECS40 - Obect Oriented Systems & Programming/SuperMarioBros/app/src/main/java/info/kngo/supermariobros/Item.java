package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Jack on 5/11/2015.
 */
public class Item implements TimeConscious {

    public int mAlpha  = 255 ;

    //Object Properties
    private MarioSurfaceView view;

    //Rect Boundary
    public Rect retrieved;
    public Rect dst;
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    //Physics
    public double mAccelY;
    public double mVelY;
    public double mVelX;

    //Booleans
    boolean mushroom = false;
    boolean fireflower = false;

    int item_type;

    //Bitmap
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmap;

    //Constructor
    public Item(MarioSurfaceView view, int x1, int y1, int item_type) {
        this.view = view;
        this.mX1 = x1;
        this.mX2 = x1 + view.getHeight()/20;
        this.mY1 = y1;
        this.mY2 = y1 + view.getHeight()/20;

        Bitmap[] bitmaps = {
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.coin, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.mushroom, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.fireflower, options),
        };
        this.item_type = item_type;
        this.bitmap = bitmaps[item_type];
    }

    public int getX1(){return mX1;}
    public int getX2(){return mX2;}
    public int getY1(){return mY1;}
    public int getY2(){return mY2;}

    @Override
    public void tick(Canvas canvas) {
        retrieved = new Rect(getX1(), getY1(), getX2(), getY2());
        draw(canvas);

        //Make items scroll
        mX1 += mVelX;
        mX2 += mVelX;
    }
    //Draws Block
    public void draw(Canvas c){
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        paint.setAlpha(mAlpha);
        dst = new Rect (getX1(), getY1(), getX2(), getY2()) ; // Where to draw .
        c.drawBitmap(bitmap, null, dst, paint) ;
    }
}
