package info.kngo.dash_till_puff;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.DashPathEffect;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.PathDashPathEffect;

import java.util.ArrayList;
import java.util.Random;

/**
 * Created by Kevin on 4/20/2015.
 */

public class Trajectory implements TimeConscious {

    //Object Properties
    private DashTillPuffSurfaceView view;

    //Class Properties
    public ArrayList<Point2D> points;
    Point2D p;

    private int Velocity = -20;
    float initialX, initialY;
    Random random = new Random();

    //Constructor
    public Trajectory (DashTillPuffSurfaceView view){
        this.view = view;
        this.initialX = view.getWidth() + view.getWidth()/4;
        this.points = new ArrayList<>();
    }

    @Override
    public void tick ( Canvas canvas ) {
        // As time ticks , append more points to the trajectory and
        // discard those points that have crossed the entire
        // span of the screen .

        //For the start of the game, put the first point into the array
        if(points.isEmpty()){
            initialY = random.nextInt(view.getHeight()/2) + view.getHeight()/4;
            p = new Point2D(initialX,initialY);
            points.add(p);
        }

        //Add a new point to the Trajectory line
        if(points.get(points.size() - 1).x <= view.getWidth()){
            initialY = random.nextInt(view.getHeight()/2) + view.getHeight()/4;
            p = new Point2D(initialX,initialY);
            points.add(p);
        }

        //Draw Trajectory line
        draw (canvas) ;

        //Moves Trajectory line to the left
        int listSize = points.size();
        for ( int i = 0; i < listSize; ++ i ) {
            points.get(i).x += Velocity;
        }
        //Remove the first point in the list if it goes out of the screen's view
        if(points.get(0).x <= 0){
            points.remove(0);
        }
    }

    private void draw(Canvas c){
        Path path = new Path() ;

        // Start Path creation. Move to first point
        path.moveTo(points.get(0).x , points.get(0).y);
        //Creates the rest of the path by appending more points to be drawn
        for ( int i = 1; i < points.size () ; ++ i ) {
            p  = points.get(i);
            path.lineTo ( p.x , p.y );
        }

        //Draw the Path
        Paint paint = new Paint () ;
        // Set paint color , alpha , line width , dashed style , etc .
        paint.setAlpha(255);
        paint.setStrokeWidth(10);
        paint.setColor(Color.MAGENTA);
        paint.setAntiAlias(true);
        paint.setStyle(Paint.Style.FILL_AND_STROKE);
        paint.setPathEffect(new DashPathEffect(new float[]{50, 100}, 100));
        c . drawPath ( path , paint ) ;
    }

}
