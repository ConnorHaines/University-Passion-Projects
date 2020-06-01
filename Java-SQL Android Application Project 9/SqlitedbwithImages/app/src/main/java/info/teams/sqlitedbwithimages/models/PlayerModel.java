package info.teams.sqlitedbwithimages.models;

/**
 * **/

public class PlayerModel {

    //private variables
    int _id;
    String _pname,pposition;
    int _fid;



    // Empty constructor
    public PlayerModel(){

    }


    // constructor
    public PlayerModel(String pname, String pposition , int fid){

        this._pname = pname;
        this.pposition = pposition;
        this._fid = fid;
    }

    public String getPposition() {
        return pposition;
    }

    public void setPposition(String pposition) {
        this.pposition = pposition;
    }

    // getting ID
    public int getID(){
        return this._id;
    }

    // setting id
    public void setID(int id){
        this._id = id;
    }

    // getting name
    public String getPName(){
        return this._pname;
    }

    // setting name
    public void setPName(String pname){
        this._pname = pname;
    }

    //getting profile pic
    public int getFID(){
      return this._fid;
    }

    //setting profile pic

    public void setFID(int fid) {
        this._fid = fid;
    }
}