package info.teams.sqlitedbwithimages.adapters;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

import info.teams.sqlitedbwithimages.R;
import info.teams.sqlitedbwithimages.models.PlayerModel;

public class playerRecordAdapter extends RecyclerView.Adapter<playerRecordAdapter.MyViewHolder> {
    ArrayList<PlayerModel>arrayList;
    Activity activity;

    public playerRecordAdapter(ArrayList<PlayerModel> arrayList, Activity activity) {
        this.arrayList = arrayList;
        this.activity = activity;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view= LayoutInflater.from(activity).inflate(R.layout.listplayer,parent,false);
        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        PlayerModel players=arrayList.get(position);
        holder.pname.setText(players.getPName());
        holder.pposition.setText(players.getPposition());

    }

    @Override
    public int getItemCount() {
        return arrayList.size();
    }
    private Bitmap convertToBitmap(byte[] b){

        return BitmapFactory.decodeByteArray(b, 0, b.length);

    }

    public void setdata(ArrayList<PlayerModel> arrayList) {
        this.arrayList=arrayList;
        notifyDataSetChanged();
    }



    class MyViewHolder extends RecyclerView.ViewHolder
    {
        TextView pname,pposition;
        MyViewHolder(@NonNull View itemView) {
            super(itemView);
            pname=itemView.findViewById(R.id.pname);
            pposition=itemView.findViewById(R.id.pposition);

        }
    }
}
