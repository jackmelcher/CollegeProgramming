package info.kngo.supermariobros;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by Kevin on 5/11/2015.
 */
public class ControllerLayout implements TimeConscious{
    //MarioSurfaceView
    private MarioSurfaceView view;
    //Bitmap options
    BitmapFactory. Options options = new BitmapFactory . Options () ;
    //Bitmap variables
    Bitmap control_a, control_b, control_dpad;
    //Rectangles for controller layout
    Rect dst_a, dst_b, dst_dpad;

    public ControllerLayout(MarioSurfaceView view){
        this.view = view;

        control_a = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.control_a, options);
        control_b = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.control_b, options);
        control_dpad = BitmapFactory.decodeResource(this.view.getResources(), R.drawable.control_dpad, options);
    }
    public void tick(Canvas canvas){
        draw(canvas);
    }

    public void draw(Canvas canvas){
        Paint paint = new Paint();
        paint.setAntiAlias(true);
        //Set the transparency on controller layout
        paint.setAlpha(100);
        //A button
        dst_a = new Rect (view.getWidth() - 200, view.getHeight()/2 - 100, view.getWidth(), view.getHeight()/2 + 100);
        canvas.drawBitmap(control_a, null, dst_a, paint) ;
        //B button
        dst_b = new Rect (view.getWidth()- 400, view.getHeight()/2, view.getWidth() - 200, view.getHeight()/2 + 200);
        canvas.drawBitmap(control_b, null, dst_b, paint) ;
        //Dpad buttons
        dst_dpad = new Rect (200 - 128, view.getHeight()/2 - 128, 200 + 128, view.getHeight()/2 + 128);
        canvas.drawBitmap(control_dpad, null, dst_dpad, paint) ;
    }

}
