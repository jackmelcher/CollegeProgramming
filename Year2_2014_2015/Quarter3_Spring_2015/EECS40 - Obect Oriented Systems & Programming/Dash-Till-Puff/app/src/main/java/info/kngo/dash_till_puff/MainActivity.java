package info.kngo.dash_till_puff;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;


public class MainActivity extends Activity {
    @Override
    protected void onCreate ( Bundle savedInstanceState ) {
        super . onCreate ( savedInstanceState ) ;
        setContentView ( new DashTillPuffSurfaceView ( getBaseContext () ) ) ;
    }
}

