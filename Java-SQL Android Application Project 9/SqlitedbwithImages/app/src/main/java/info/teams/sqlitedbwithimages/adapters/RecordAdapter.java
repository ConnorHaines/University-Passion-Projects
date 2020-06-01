package info.teams.sqlitedbwithimages.adapters;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AlertDialog;
import androidx.cardview.widget.CardView;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

import info.teams.sqlitedbwithimages.R;
import info.teams.sqlitedbwithimages.activities.DisplayPlayersList;
import info.teams.sqlitedbwithimages.activities.PlayersActivity;
import info.teams.sqlitedbwithimages.activities.editActivity;
import info.teams.sqlitedbwithimages.interfaces.MyInterfaces;
import info.teams.sqlitedbwithimages.models.Team;

public class RecordAdapter extends RecyclerView.Adapter<RecordAdapter.MyViewHolder> {
    ArrayList<Team>arrayList;
    Activity activity;
    MyInterfaces.deleteRecord deleteRecord;
    MyInterfaces.updateRecord updateRecord;
    public RecordAdapter(ArrayList<Team> arrayList, Activity activity) {
        this.arrayList = arrayList;
        this.activity = activity;
    }

    @NonNull
    @Override
    public MyViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view= LayoutInflater.from(activity).inflate(R.layout.listteams,parent,false);
        return new MyViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull MyViewHolder holder, int position) {
        final Team team=arrayList.get(position);
        holder.teamLogo.setImageBitmap(convertToBitmap(team.getImage()));
        holder.temaname.setText("Team Name  "+team.getFName());
        holder.teamsize.setText("Team Size  "+team.getTeamsize());
        holder.teamLogo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
//                Intent intent=new Intent(activity, editActivity.class);
//                intent.putExtra("team", team);
//                activity.startActivity(intent);
                playersDialog(String.valueOf(team.getID()));
            }
        });
        holder.delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                deleteRecord.onDeleteRecord(team.getID());
            }
        });
        holder.edit.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                updateRecord.onUpdateRecord(team.getID());

            }
        });
    }

    @Override
    public int getItemCount() {
        return arrayList.size();
    }
    private Bitmap convertToBitmap(byte[] b){

        return BitmapFactory.decodeByteArray(b, 0, b.length);

    }

    public void setdata(ArrayList<Team> arrayList) {
        this.arrayList=arrayList;
        notifyDataSetChanged();
    }

    class MyViewHolder extends RecyclerView.ViewHolder
    {
        ImageView teamLogo;
        TextView temaname,teamsize;
        CardView cardinfo;
        ImageButton edit,delete;
        MyViewHolder(@NonNull View itemView) {
            super(itemView);
            temaname=itemView.findViewById(R.id.txtViewer);
            teamsize=itemView.findViewById(R.id.teamsize);
            teamLogo=itemView.findViewById(R.id.imgView);
            cardinfo=itemView.findViewById(R.id.cardinfo);
            edit=itemView.findViewById(R.id.edit);
            delete=itemView.findViewById(R.id.delete);
        }
    }

    public void setDeleteRecord(MyInterfaces.deleteRecord deleteRecord) {
        this.deleteRecord = deleteRecord;
    }

    public void setUpdateRecord(MyInterfaces.updateRecord updateRecord) {
        this.updateRecord = updateRecord;
    }
    private void playersDialog(final String cid)
    {
        AlertDialog.Builder builder1 = new AlertDialog.Builder(activity);
        builder1.setMessage("Add or display players");
        builder1.setCancelable(true);

        builder1.setPositiveButton(
                "Diplay Players",
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        Intent intent=new Intent(activity, DisplayPlayersList.class);
                        intent.putExtra("teamid",cid);
                        activity.startActivity(intent);
                    }
                });
        builder1.setNegativeButton(
                "Add Players",
                new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                        Intent intent=new Intent(activity, PlayersActivity.class);
                        intent.putExtra("teamid",cid);
                        activity.startActivity(intent);
                    }
                });

        AlertDialog alert11 = builder1.create();
        alert11.show();
    }
}
