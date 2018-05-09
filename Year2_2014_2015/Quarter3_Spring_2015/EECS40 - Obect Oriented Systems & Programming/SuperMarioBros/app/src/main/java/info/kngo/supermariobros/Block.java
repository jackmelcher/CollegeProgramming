package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Kevin on 5/11/2015.
 */
public class Block implements TimeConscious{
    //Object Properties
    private MarioSurfaceView view;
    int blockSize;
    int block_type;
    public int mAlpha  = 255 ;

    //Stored item in block
    int item_type;

    //Rect Boundary
    public Rect rect_top;
    public Rect rect_bottom;
    public Rect rect_left;
    public Rect rect_right;
    public int mX1;
    public int mX2;
    public int mY1;
    public int mY2;

    //Velocity
    public int mVelX;

    //Bitmaps
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    Bitmap bitmap;
    Bitmap bitmaps[];

    //Boolean
    boolean emptyBlock = false;

    //Block item
    Item blockItem;

    //Constructor
    public Block(MarioSurfaceView view, int x1, int y1,  int block_type, int item_type){
        this.view = view;
        this.mX1 = x1;
        this.mY1 = y1;
        if(block_type == 3){
            this.mX2 = x1 + view.getWidth() + view.getHeight()/20;
            this.mY2 = view.getHeight();
        }
        else if(block_type == 4){
            this.mX2 = x1 + 2*view.getHeight()/20;
            this.mY2 = y1 + 6*view.getHeight()/20;
        }
        else{
            this.mX2 = x1 + view.getHeight()/20;
            this.mY2 = y1 + view.getHeight()/20;
        }

        if(block_type == 4){
            this.mX2 = x1 + view.getHeight()/10;
            this.mY2 = y1 + view.getHeight()/10;
        }

        Bitmap[] bitmaps = {
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.block_brick, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.block_question, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.block_empty, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.tile_floor, options),
                BitmapFactory.decodeResource(this.view.getResources(), R.drawable.pipe_tall, options),
        };
        this.block_type = block_type;
        this.bitmap = bitmaps[block_type];
        this.bitmaps = bitmaps;
        this.blockSize = view.getHeight()/20;
        this.item_type = item_type;
    }

    public int getX1(){return mX1;}
    public int getX2(){return mX2;}
    public int getY1(){return mY1;}
    public int getY2(){return mY2;}

    @Override
    public void tick(Canvas canvas) {

        rect_top = new Rect(getX1(), getY1(), getX2(), getY2() - blockSize/4);
        rect_bottom = new Rect(getX1()+blockSize/2, getY1() + blockSize/2, getX2()-blockSize/2, getY2()+blockSize/2);
        rect_left = new Rect(getX1(), getY1(), getX2() - blockSize/2, getY2());
        rect_right = new Rect(getX1()+ blockSize/2, getY1(), getX2(), getY2());

        if(block_type == 4){
            rect_left = new Rect(getX1(), getY1(), getX2() - blockSize, getY2());
            rect_right = new Rect(getX1()+ blockSize, getY1(), getX2(), getY2());
        }

        if(emptyBlock){
            bitmap = bitmaps[2];
        }


        draw(canvas);

        //Make blocks scroll
        mX1 += mVelX;
        mX2 += mVelX;
    }
    //Draws Block
    public void draw(Canvas c){
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        paint.setAlpha(mAlpha);
        Rect dst = new Rect (getX1(), getY1(), getX2(), getY2()) ; // Where to draw .
        c.drawBitmap(bitmap, null, dst, paint) ;

    }
}

