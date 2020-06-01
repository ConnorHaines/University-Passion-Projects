package info.teams.sqlitedbwithimages.adapters;

        import android.content.Context;
        import android.graphics.Bitmap;
        import android.graphics.BitmapFactory;
        import android.view.LayoutInflater;
        import android.view.View;
        import android.view.ViewGroup;
        import android.widget.ArrayAdapter;
        import android.widget.ImageView;
        import android.widget.TextView;
        import android.widget.Toast;

        import java.util.ArrayList;

        import info.teams.sqlitedbwithimages.R;
        import info.teams.sqlitedbwithimages.models.Team;

/**
 * **/

public class dataAdapter extends ArrayAdapter<Team>{

    Context context;
    ArrayList<Team> mteam;


    public dataAdapter(Context context, ArrayList<Team> team){
        super(context, R.layout.listteams, team);
        this.context=context;
        this.mteam=team;
    }

    public  class  Holder{
        TextView nameFV;
        ImageView pic;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        // Get the data item for this position

        Team data = getItem(position);
        // Check if an existing view is being reused, otherwise inflate the view

        Holder viewHolder; // view lookup cache stored in tag

        if (convertView == null) {


            viewHolder = new Holder();
            LayoutInflater inflater = LayoutInflater.from(getContext());
            convertView = inflater.inflate(R.layout.listteams, parent, false);

            viewHolder.nameFV = (TextView) convertView.findViewById(R.id.txtViewer);
            viewHolder.pic = (ImageView) convertView.findViewById(R.id.imgView);


            convertView.setTag(viewHolder);
        } else {
            viewHolder = (Holder) convertView.getTag();
        }


        viewHolder.nameFV.setText("Team Name: "+data.getFName());
        viewHolder.pic.setImageBitmap(convertToBitmap(data.getImage()));
        Toast.makeText(context, ""+data.getTeamsize(), Toast.LENGTH_SHORT).show();


        // Return the completed view to render on screen
        return convertView;
    }
    //get bitmap image from byte array

    private Bitmap convertToBitmap(byte[] b){

        return BitmapFactory.decodeByteArray(b, 0, b.length);

    }

}

