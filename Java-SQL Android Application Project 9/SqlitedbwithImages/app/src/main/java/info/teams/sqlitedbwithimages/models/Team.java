package info.teams.sqlitedbwithimages.models;

import java.io.Serializable;

/**
 * **/

public class Team implements Serializable {

    //private variables
    int _id;
    String _fname,teamsize;
    byte[] _img;



    // Empty constructor
    public Team(){

    }
    // constructor
    public Team(int id, String fname,String teamsize, byte[] img){
        this._id = id;
        this._fname = fname;
        this.teamsize=teamsize;
        this._img = img;

    }

    // constructor
    public Team(String fname, byte[] img,String teamsize){

        this._fname = fname;
        this._img = img;
        this.teamsize=teamsize;
    }

    public String getTeamsize() {
        return teamsize;
    }

    public void setTeamsize(String teamsize) {
        this.teamsize = teamsize;
    }

    // getting ID
    public int getID(){
        return this._id;
    }

    // setting id
    public void setID(int id){
        this._id = id;
    }

    // getting first name
    public String getFName(){
        return this._fname;
    }

    // setting first name
    public void setFName(String fname){
        this._fname = fname;
    }

    //getting profile pic
    public byte[] getImage(){
        return this._img;
    }

    //setting profile pic

    public void setImage(byte[] b){
        this._img=b;
    }

}

