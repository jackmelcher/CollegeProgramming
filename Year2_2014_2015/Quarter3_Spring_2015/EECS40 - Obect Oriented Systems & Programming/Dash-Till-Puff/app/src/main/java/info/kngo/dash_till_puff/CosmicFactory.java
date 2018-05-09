package info.kngo.dash_till_puff;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import java.util.ArrayList;
import java.util.Random;

/**
 * Created by Jack on 4/20/2015.
 */
public class CosmicFactory implements TimeConscious {
    //DashTillPuffSurfaceView
    DashTillPuffSurfaceView view;

    //Array list for clusters
    public ArrayList<CosmicObject> cluster;

    //Object declaration
    CosmicObject cosmicobject;

    boolean alternate = true;

    //Random object variable
    int selection = 0;
    //Distance between objects
    int deltaX = 100;
    //Offset from the trajectory line
    int deltaY = 192;
    //Counts number of cluster has spawned, max of 10
    int count = 0;
    //The spawning location of the cosmic object
    int initialX, initialY;

    //Constructor
    CosmicFactory(DashTillPuffSurfaceView view){
        this.view = view;
        this.cluster = new ArrayList<>();
        //Area beyond in which the object spawns
        initialX = view.getWidth();
    }

    @Override
    public void tick ( Canvas canvas ) {
        // Create new ‘‘ clusters ’’ of cosmic objects . Alternately place
        // clusters of cosmic objects above and below the guiding
        // trajectory .

        //Random object
        Random rand = new Random();
        //Maximum size of the object
        int maxSize = 64;

        // Randomly select the type of cluster objects from a list
        // ( e . g . , stars , clouds , planets , etc .) . So all objects in
        // a cluster are of the same type .

        //After 10 of the same objects are added, select next random cosmic object
        if(count >= 10){
            //Randomly select different bitmap for next 10 cosmic objects
            selection = rand.nextInt(10);
            //Change whether objects spawn above or below line
            alternate = !alternate;
            count = 0;
        }
        //Variables to help determine placement of cosmic object
        float x1 = view.trajectory.points.get(view.trajectory.points.size()-2).x,
              x2 = view.trajectory.points.get(view.trajectory.points.size()-1).x,
              x3 = view.getWidth(),
              y1 = view.trajectory.points.get(view.trajectory.points.size()-2).y,
              y2 = view.trajectory.points.get(view.trajectory.points.size()-1).y,
              y3;




        //Spawn new cosmic objects
        if(view.trajectory.points.size() > 1) {
            //Determine spawn height
            y3 = ((y2-y1)*(x3-x1)/(x2-x1) + y1);
            //Spawn cosmic objects above trajectory line
            if (alternate) {
                //deltaY = rand.nextInt(view.getWidth() - (int)y3- 192);
                initialY = (int)rand.nextInt((int)y3- 192);
                //If array list is empty
                if(cluster.isEmpty()) {
                    CosmicObject cosmicobject = new CosmicObject(view, initialX - maxSize, initialY - maxSize, initialX + maxSize, initialY + maxSize, selection);
                    cluster.add(cosmicobject);
                    count++;
                }
                else if (cluster.get(cluster.size() - 1).mX2 <= view.getWidth()) {
                    CosmicObject cosmicobject = new CosmicObject(view, initialX - maxSize, initialY - maxSize, initialX + maxSize, initialY + maxSize, selection);
                    cluster.add(cosmicobject);
                    count++;
                }
            }
            //Spawn cosmic object below trajectory line
            else if (!alternate) {
               // deltaY = rand.nextInt((int)y3 - 192);
                initialY = (int)y3 + 192 + rand.nextInt(view.getHeight() - (int)y3 - 192);
                //If array list is empty
                if(cluster.isEmpty()) {
                    CosmicObject cosmicobject = new CosmicObject(view, initialX - maxSize, initialY - maxSize, initialX + maxSize, initialY + maxSize, selection);
                    cluster.add(cosmicobject);
                    count++;
                }
                else if (cluster.get(cluster.size() - 1).mX2 <= view.getWidth()) {
                    CosmicObject cosmicobject = new CosmicObject(view, initialX - maxSize, initialY - maxSize, initialX + maxSize, initialY + maxSize, selection);
                    cluster.add(cosmicobject);
                    count++;
                }
            }
        }

        //Draw the clusters
        for(int i = 0; i < cluster.size(); i++){
            cluster.get(i).draw(canvas);
        }

        // Remove cosmic objects ( stars , planets , etc .) that moved out
        // of the scene .
        for(int i = 0; i < cluster.size(); i++){
            if(cluster.get(i).mX2 <= 0){
                cluster.remove(i);
            }
        }
    }
}
