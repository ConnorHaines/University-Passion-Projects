package info.teams.sqlitedbwithimages.adapters;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

import info.teams.sqlitedbwithimages.R;

import info.teams.sqlitedbwithimages.models.PlayerModel;

/**
 * **/

public class playerDataAdapter extends ArrayAdapter<PlayerModel>{

    Context context;
    ArrayList<PlayerModel> mplayers;


    public playerDataAdapter(Context context, ArrayList<PlayerModel> player){
        super(context, R.layout.listplayer, player);
        this.context=context;
        this.mplayers=player;
    }



    public  class  Holder{
        TextView name;
        TextView pos;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        // Get the data item for this position

        PlayerModel data = getItem(position);
        // Check if an existing view is being reused, otherwise inflate the view

        Holder viewHolder; // view lookup cache stored in tag

        if (convertView == null) {


            viewHolder = new Holder();
            LayoutInflater inflater = LayoutInflater.from(getContext());
            convertView = inflater.inflate(R.layout.listplayer, parent, false);

            viewHolder.name = (TextView) convertView.findViewById(R.id.txtViewer);
            viewHolder.pos = (TextView) convertView.findViewById(R.id.txtViewer);


            convertView.setTag(viewHolder);
        } else {
            viewHolder = (Holder) convertView.getTag();
        }


        viewHolder.name.setText("Player: "+data.getPName());
        viewHolder.name.setText("Position: "+data.getPposition());



        // Return the completed view to render on screen
        return convertView;
    }
    //get bitmap image from byte array


}

