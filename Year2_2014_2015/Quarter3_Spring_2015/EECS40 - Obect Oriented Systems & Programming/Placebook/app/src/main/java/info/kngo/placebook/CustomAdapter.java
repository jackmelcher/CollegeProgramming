package info.kngo.placebook;

import java.util.List;
import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

// The following class is based on a class I found online
// http://theopentutorials.com/post/uncategorized/android-custom-listview-with-image-and-text-using-baseadapter/
public class CustomAdapter extends BaseAdapter {
    Context context;
    List<PlacebookEntry> mPlacebookEntries;
    BitmapFactory.Options options = new BitmapFactory . Options () ;

    public CustomAdapter(Context context, List<PlacebookEntry> items) {
        this.context = context;
        this.mPlacebookEntries = items;
    }

    /*private view holder class*/
    private class ViewHolder {
        ImageView imageView;
        TextView txtTitle;
        TextView txtDesc;
    }

    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder = null;

        LayoutInflater mInflater = (LayoutInflater)
                context.getSystemService(Activity.LAYOUT_INFLATER_SERVICE);
        if (convertView == null) {
            convertView = mInflater.inflate(R.layout.row_layout, null);
            holder = new ViewHolder();
            holder.txtDesc = (TextView) convertView.findViewById(R.id.row_txtPlaceDesc);
            holder.txtTitle = (TextView) convertView.findViewById(R.id.row_txtPlace);
            holder.imageView = (ImageView) convertView.findViewById(R.id.row_image_view);
            convertView.setTag(holder);
        }
        else {
            holder = (ViewHolder) convertView.getTag();
        }

        PlacebookEntry placebookEntry = (PlacebookEntry) getItem(position);

        holder.txtDesc.setText(placebookEntry.getDesc());
        holder.txtTitle.setText(placebookEntry.getTitle());

        Matrix matrix = new Matrix();
        matrix.postRotate(90);

        if(placebookEntry.getImageId() != null) {
            Bitmap scaledBitmap = Bitmap.createScaledBitmap(BitmapFactory.decodeFile(placebookEntry.getImageId(), options), 75, 75, false);

            Bitmap rotatedBitmap = Bitmap.createBitmap(scaledBitmap, 0, 0, scaledBitmap.getWidth(), scaledBitmap.getHeight(), matrix, true);

            holder.imageView.setImageBitmap(rotatedBitmap);
        }
        return convertView;
    }

    @Override
    public int getCount() {
        return mPlacebookEntries.size();
    }

    @Override
    public Object getItem(int position) {
        return mPlacebookEntries.get(position);
    }

    @Override
    public long getItemId(int position) {
        return mPlacebookEntries.indexOf(getItem(position));
    }
}