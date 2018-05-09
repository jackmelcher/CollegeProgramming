package info.kngo.placebook;

import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.Intent;
import android.content.IntentSender;
import android.net.Uri;
import android.os.Environment;
import android.provider.MediaStore;
import android.speech.RecognizerIntent;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ImageButton;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GooglePlayServicesNotAvailableException;
import com.google.android.gms.common.GooglePlayServicesRepairableException;
import com.google.android.gms.common.api.GoogleApiClient;
import com.google.android.gms.location.places.Place;
import com.google.android.gms.location.places.Places;
import com.google.android.gms.location.places.ui.PlacePicker;
import java.io.File;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Locale;
import info.kngo.placebook.R;


public class MainActivity extends ActionBarActivity
        implements GoogleApiClient.ConnectionCallbacks, GoogleApiClient.OnConnectionFailedListener, AdapterView.OnItemClickListener {

    //Google API Client
    GoogleApiClient mGoogleApiClient;
    // Unique tag for the error dialog fragment
    private static final String DIALOG_ERROR = "dialog_error";
    // Bool to track whether the app is already resolving an error
    private boolean mResolvingError = false;

    static final int REQUEST_IMAGE_CAPTURE = 1001;
    static final int REQUEST_SPEECH_INPUT = 1002;
    static final int REQUEST_RESOLVE_ERROR = 1003;
    static final int REQUEST_PLACE_PICKER = 1004;
    private static final int REQUEST_VIEW_ALL = 1005;

    public static final String VIEW_ALL_KEY = " info . kngo . placebook . EXTRA_VIEW_ALL ";

    private TextView txtPlaceContent;
    private TextView edit_place_desc;

    CustomAdapter adapter;
    ListView mListview;
    List<PlacebookEntry> mPlacebookEntries;
    PlacebookEntry entry;
    String imageId;
    String title;
    String description;
    int listPosition;

    //File creation
    File photoFile;



    //Code made on project creation
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initGoogleApi();

        mPlacebookEntries = new ArrayList<>();
        txtPlaceContent = (TextView) findViewById(R.id.txtPlaceContent);
        edit_place_desc = (TextView) findViewById(R.id.edit_place_desc);

        //Create new listview
        mListview = (ListView) findViewById(R.id.listview);
        CustomAdapter adapter = new CustomAdapter(this, mPlacebookEntries);
        mListview.setAdapter(adapter);
        mListview.setOnItemClickListener(this);
    }

    //Added in from assignment pdf
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        //Inflate the menu; this add items to the action bar
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        //Handle action bar item clicks here. The action bar will
        //Automatically clicks on the Home/Up button, so long
        //as you specify a parent activity in AndroidManifest.xml
        switch (item.getItemId()) {
            /* * Code to show settings * */
            case R.id.action_settings:
                //No Settings for this project
                return true;
            /* * Code to add a new place * */
            case R.id.action_new_place:

                title = txtPlaceContent.getText().toString();
                description = edit_place_desc.getText().toString();

                //Construct a new Placebook Entry
                entry = new PlacebookEntry(imageId, title, description);
                mPlacebookEntries.add(entry);

                //Update Listview
                adapter = new CustomAdapter(this, mPlacebookEntries);
                mListview.setAdapter(adapter);

                //Clear textview strings and the imageId string
                txtPlaceContent.setText("");
                edit_place_desc.setText("");
                imageId = null;

                return true;
            //Code to Edit a Place
            case R.id.action_edit_place:

                //Construct a new Placebook Entry
                title = txtPlaceContent.getText().toString();
                description = edit_place_desc.getText().toString();

                entry = new PlacebookEntry(imageId, title, description);

                mPlacebookEntries.set(listPosition, entry);

                //Update Listview
                adapter = new CustomAdapter(this, mPlacebookEntries);
                mListview.setAdapter(adapter);

                //Clear textview strings and the imageId string
                txtPlaceContent.setText("");
                edit_place_desc.setText("");

                return true;
            //Code to Delete a Place
            case R.id.action_delete_place:
                mPlacebookEntries.remove(listPosition);

                //Update Listview
                adapter = new CustomAdapter(this, mPlacebookEntries);
                mListview.setAdapter(adapter);

                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position,
                            long id) {
        //Print message to screen to verify selection
        Toast toast = Toast.makeText(getApplicationContext(),
                "Item " + (position) + ": " + mPlacebookEntries.get(position),
                Toast.LENGTH_SHORT);
        toast.setGravity(Gravity.BOTTOM| Gravity.CENTER_HORIZONTAL, 0, 0);
        toast.show();

        //Get the selected position so it can be used for edit or delete
        listPosition = position;

        //If you want to keep the image from the entry you want to edit, selecting the entry will give you that image.
        if(!mPlacebookEntries.isEmpty()){
            imageId = mPlacebookEntries.get(position).getImageId();
        }
    }



    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        if ( resultCode == RESULT_OK && requestCode == REQUEST_PLACE_PICKER && data != null ) {
            Place place = PlacePicker . getPlace(data, this) ;
            // Set place name text view to place . getName () .
            String toastMsg = String.format("Place: %s", place.getName());

            //Display place location
            Toast.makeText(this, toastMsg, Toast.LENGTH_LONG).show();

            //Set "Place" content after selection of place
            txtPlaceContent.setText(place.getName());
        }
        if (resultCode == RESULT_OK && requestCode == REQUEST_SPEECH_INPUT && data != null) {
            ArrayList<String> result = data.getStringArrayListExtra(RecognizerIntent.EXTRA_RESULTS);
            // Append result . get (0) to the place name or description text view
            // according to which one had focus when voice recognizer was launched .


            //Speech input into place location
            if(this.txtPlaceContent.hasFocus()) {
                txtPlaceContent.setText(result.get(0));
            }
            //Speech input into place ddescription
            if(this.edit_place_desc.hasFocus()){
                edit_place_desc.setText(result.get(0));
            }
        }

        if(resultCode == RESULT_OK && requestCode == REQUEST_IMAGE_CAPTURE){
            
            if(photoFile != null) {
                imageId = photoFile.getAbsolutePath();
            }

        }

        //Handle Connection Failure for Place Picker
        if (requestCode == REQUEST_RESOLVE_ERROR) {
            mResolvingError = false;
            if (resultCode == RESULT_OK) {
                // Make sure the app is not already connected or attempting to connect
                if (!mGoogleApiClient.isConnecting() &&
                        !mGoogleApiClient.isConnected()) {
                    mGoogleApiClient.connect();
                }
            }
        }
    }


    //Called when image button is pressed
    public void sendImageMessage(View view) {
        // Do something in response to button click
        ImageButton btnSnapshot = ( ImageButton ) findViewById ( R. id .button_snapshot);
        btnSnapshot.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Code to be executed when the button is clicked .
                dispatchTakePictureIntent();
            }
        }) ;
    }

    //Called when place picker button is pressed
    public void sendPlacePickerMessage(View view) {
        // Do something in response to button click
        ImageButton btnPlacePicker = ( ImageButton ) findViewById ( R. id .button_place_picker);
        btnPlacePicker.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Code to be executed when the button is clicked .
                launchPlacePicker();
            }
        }) ;
    }

    //Called when speak button is pressed
    public void sendSpeakMessage(View view) {
        // Do something in response to button click
        ImageButton btnSpeak = ( ImageButton ) findViewById ( R. id .button_speak);
        btnSpeak.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // Code to be executed when the button is clicked .
               dispatchSpeechInputIntent();
            }
        }) ;
    }

    // Call dispatchTakePictureIntent when the camera button is clicked .
    private void dispatchTakePictureIntent () {
        Intent takePictureIntent = new Intent ( MediaStore . ACTION_IMAGE_CAPTURE );
        // Ensure that there is a camera activity to handle the intent
        if ( takePictureIntent . resolveActivity ( getPackageManager () ) != null ) {

            //File name parameters
            String fileExt = ".jpg";
            String sdf = new SimpleDateFormat("yyyy_MM_dd_HH_mm_ss").format(new Date());
            String fileName = sdf + "_Placebook";


            //Storage directory
            File storageDir = Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_PICTURES);


            try {
                //Save image into designated storage directory
                photoFile = File.createTempFile(fileName, fileExt, storageDir);
                System.out.println("photofile = " + photoFile.getAbsolutePath());

            }
            catch(IOException ex){
                //Print the stack trace if file creation failed
                ex.printStackTrace();
                return;
            }
            takePictureIntent . putExtra(MediaStore.EXTRA_OUTPUT, Uri.fromFile(photoFile)) ;
            startActivityForResult(takePictureIntent, REQUEST_IMAGE_CAPTURE) ;


        } else {
            CharSequence textMessage = "No camera app installed";
            int duration = Toast.LENGTH_SHORT;
            Toast . makeText (this, textMessage, duration). show () ;
        }
    }

    // Call dispatchSpeechInputIntent() when the speech - to - text button is clicked .
    void dispatchSpeechInputIntent () {

        Intent intent = new Intent ( RecognizerIntent . ACTION_RECOGNIZE_SPEECH );
        intent . putExtra (
                RecognizerIntent . EXTRA_LANGUAGE_MODEL ,
                RecognizerIntent . LANGUAGE_MODEL_FREE_FORM );
        intent . putExtra (
                RecognizerIntent . EXTRA_LANGUAGE , Locale. getDefault() );
        intent . putExtra(
                RecognizerIntent.EXTRA_PROMPT,
                getString(R.string.speech_prompt));
        try {
            startActivityForResult ( intent , REQUEST_SPEECH_INPUT );
        } catch ( ActivityNotFoundException a ) {
            // Handle Exception
            Toast.makeText(getApplicationContext(),
                    getString(R.string.speech_not_supported),
                    Toast.LENGTH_SHORT).show();
        }
    }

    // Call initGoogleApi() from MainActivity . onCreate ()
    private void initGoogleApi () {
                mGoogleApiClient = new GoogleApiClient
                . Builder ( this )
                . addApi(Places.GEO_DATA_API)
                . addApi(Places.PLACE_DETECTION_API)
                . addConnectionCallbacks(this)
                . addOnConnectionFailedListener(this)
                . build() ;
    }
    // Call launchPlacePicker() when the Pick -A- Place button is clicked .
    private void launchPlacePicker () {
        PlacePicker . IntentBuilder builder = new PlacePicker. IntentBuilder () ;
        Context context = getApplicationContext () ;
        try {
            startActivityForResult ( builder . build ( context ) , REQUEST_PLACE_PICKER );
        } catch ( GooglePlayServicesRepairableException e) {
            // Handle exception - Display a Toast message
        } catch ( GooglePlayServicesNotAvailableException e ) {
            // Handle exception - Display a Toast message
        }
    }

    //Connect to googleAPI on start
    @Override
    protected void onStart() {
        super.onStart();
        if (!mResolvingError) {  // more about this later
            mGoogleApiClient.connect();
        }
    }
    //Disconnect to googleAPI on stop
    @Override
    protected void onStop() {
        mGoogleApiClient.disconnect();
        super.onStop();
    }

    @Override
    public void onConnected(Bundle bundle) {
        // Connected to Google Play services!
        // The good stuff goes here.
    }

    @Override
    public void onConnectionSuspended(int i) {
        // The connection has been interrupted.
        // Disable any UI components that depend on Google APIs
        // until onConnected() is called.
    }

    @Override
    public void onConnectionFailed(ConnectionResult result) {
        // This callback is important for handling errors that
        // may occur while attempting to connect with Google.

        if (mResolvingError) {
            // Already attempting to resolve an error.
            return;
        } else if (result.hasResolution()) {
            try {
                mResolvingError = true;
                result.startResolutionForResult(this, REQUEST_RESOLVE_ERROR);
            } catch (IntentSender.SendIntentException e) {
                // There was an error with the resolution intent. Try again.
                mGoogleApiClient.connect();
            }
        } else {
            // Show dialog using GooglePlayServicesUtil.getErrorDialog()
            //showErrorDialog(result.getErrorCode());
            mResolvingError = true;
        }
    }

}