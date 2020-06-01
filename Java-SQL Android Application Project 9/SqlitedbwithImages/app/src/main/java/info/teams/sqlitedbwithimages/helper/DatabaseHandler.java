package info.teams.sqlitedbwithimages.helper;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

import java.util.ArrayList;
import java.util.List;

import info.teams.sqlitedbwithimages.models.Team;
import info.teams.sqlitedbwithimages.models.PlayerModel;

/**
 * **/

public class DatabaseHandler extends SQLiteOpenHelper {

    // Database Version
    private static final int DATABASE_VERSION = 1;

    // Database Name
    private static final String DATABASE_NAME = "teamsManager.db";

    // teams table name
    private static final String TABLE_TEAMS = "teams";


    // teams Table Columns names
    private static final String KEY_ID = "id";
    private static final String KEY_FNAME = "fname";
    private static final String KEY_POTO = "poto";
    private static final String KEY_TEAMSIZE = "teamsize";

    //Player table name
    private static final String TABLE_PLAYERS = "players";

    // teams Table Columns names
    private static final String KEY_ID_PLAYERS = "id";
    private static final String KEY_PNAME = "pname";
    private static final String KEY_POSITION = "position";
    private static final String KEY_FID = "fid";


    public DatabaseHandler(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    //Create tables
    @Override
    public void onCreate(SQLiteDatabase db) {
       String CREATE_TABLE_TEAMS="CREATE TABLE " + TABLE_TEAMS + "("
               + KEY_ID +" INTEGER PRIMARY KEY,"
               + KEY_FNAME +" TEXT,"
               + KEY_TEAMSIZE +" TEXT,"
               + KEY_POTO  +" BLOB" + ")";

        String CREATE_TABLE_PLAYERS="CREATE TABLE " + TABLE_PLAYERS + "("
                + KEY_ID_PLAYERS +" INTEGER PRIMARY KEY,"
                + KEY_PNAME +" TEXT,"
                + KEY_POSITION +" TEXT,"
                + KEY_FID  +" INTEGER" + ")";


        db.execSQL(CREATE_TABLE_TEAMS);
        db.execSQL(CREATE_TABLE_PLAYERS);
    }

    // Upgrading database
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

        // Drop older table if existed
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_TEAMS);
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_PLAYERS);


        // Create tables again
        onCreate(db);
    }

    /**
     * All CRUD(Create, Read, Update, Delete) Operations
     */

    //Insert values to the table teams
    public void addTeams(Team team){
        SQLiteDatabase db = this.getReadableDatabase();
        ContentValues values=new ContentValues();

        values.put(KEY_FNAME, team.getFName());
        values.put(KEY_TEAMSIZE, team.getTeamsize());
        values.put(KEY_POTO, team.getImage() );


        db.insert(TABLE_TEAMS, null, values);
        db.close();
    }

    public void addPlayers(PlayerModel players){
        SQLiteDatabase db = this.getReadableDatabase();
        ContentValues values=new ContentValues();

        values.put(KEY_PNAME, players.getPName());
        values.put(KEY_POSITION, players.getPposition());
        values.put(KEY_FID, players.getFID());


        db.insert(TABLE_PLAYERS, null, values);
        db.close();
    }


    /**
     *Getting All Teams
     **/

    public List<Team> getAllTeams() {
        List<Team> teamList = new ArrayList<Team>();
        // Select All Query
        String selectQuery = "SELECT  * FROM " + TABLE_TEAMS;

        SQLiteDatabase db = this.getWritableDatabase();
        Cursor cursor = db.rawQuery(selectQuery, null);

        // looping through all rows and adding to list
        if (cursor!=null&&cursor.moveToFirst()) {
            do {
                Team team = new Team();
                team.setID(Integer.parseInt(cursor.getString(0)));
                team.setFName(cursor.getString(1));
                team.setTeamsize(cursor.getString(2));
                team.setImage(cursor.getBlob(3));


                // Adding team to list
                teamList.add(team);
            } while (cursor.moveToNext());
        }

        // return team list
        return teamList;
    }

    public List<PlayerModel> getAllPlayers(int fid) {
        List<PlayerModel> playerList = new ArrayList<PlayerModel>();
        // Select All Query
       // String selectQuery = "SELECT  * FROM " + TABLE_PLAYERS ;
        String selectQuery = ("SELECT " +KEY_ID +","+KEY_PNAME+ ","+KEY_POSITION+","+KEY_FID+"  FROM "
                + TABLE_PLAYERS + " where `" + KEY_FID + "`="
                + fid);

        SQLiteDatabase db = this.getWritableDatabase();
        Cursor cursor = db.rawQuery(selectQuery, null);

        // looping through all rows and adding to list
        if (cursor!=null&&cursor.moveToFirst()) {
            do {
                PlayerModel player = new PlayerModel();
                player.setID(Integer.parseInt(cursor.getString(0)));
                player.setPName(cursor.getString(1));
                player.setPposition(cursor.getString(2));
                player.setFID(cursor.getInt(3));


                // Adding team to list
                playerList.add(player);
            } while (cursor.moveToNext());
        }

        // return team list
        return playerList;
    }




    /**
     *Updating single team
     **/

    public void updateTeam(Team team,String rid) {
        SQLiteDatabase db = DatabaseHandler.this.getWritableDatabase();

       try {
           db.beginTransaction();
           ContentValues values = new ContentValues();
           values.put(KEY_FNAME, team.getFName());
           values.put(KEY_TEAMSIZE, team.getTeamsize());
           values.put(KEY_POTO, team.getImage());


           // updating row
           db.update(TABLE_TEAMS, values,  "id=?", new String[]{String.valueOf(rid)});
           db.setTransactionSuccessful();
           db.endTransaction();
           db.close();
           db.close();
       } catch (Exception e) {
           e.printStackTrace();
           Log.d("e",e.getMessage());
       }

    }

    public int updatePlayers(PlayerModel player, int id) {
        SQLiteDatabase db = this.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put(KEY_PNAME, player.getPName());
        values.put(KEY_POSITION, player.getPposition());


        // updating row
        return db.update(TABLE_PLAYERS, values, KEY_ID + " = ?",
                new String[] { String.valueOf(id) });
    }

    /**
     *Deleting single team
     **/

    public void deleteTeam(int Id) {
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(TABLE_TEAMS, KEY_ID + " = ?",
                new String[] { String.valueOf(Id) });
        db.delete(TABLE_PLAYERS, KEY_ID + " = ?",
                new String[] { String.valueOf(Id) });
        db.close();
    }

    public void deletePlayer(int Id) {
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(TABLE_PLAYERS, KEY_ID + " = ?",
                new String[] { String.valueOf(Id) });
        db.close();
    }

}
