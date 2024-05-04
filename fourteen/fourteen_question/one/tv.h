#ifndef TV_H_
#define TV_H_

class Remote;

class Tv{
    private:
    friend class Remote;
    int state;
    int volume;
    int maxChannel;
    int channel;
    int mode;
    int input;
    public: 
    enum {Off , On};
    enum {MinVal , MaxVal = 20};
    enum {Antenna , Cable};
    enum {TV , DVD};
    Tv(int s = Off , int mc = 125) : state(s) , volume(5) , maxChannel(mc) , channel(2) , mode(Cable) , input(TV){}
    void onoff() {state = (state == On) ? Off : On;}
    bool ison() const{ return state == On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_tv_mode(){ mode = (mode == Antenna)? Cable : Antenna; }
    void set_remote_mode(Remote & r);
    void set_input() {input = (input == TV)? DVD : TV;}
    void settings() const;
};

class Remote{
    private:
    friend class Tv;
    int tv_mode;
    int remote_mode;
    public: 
    enum {NORMAL , INTERACTIVE};
    Remote(int tm = Tv::TV , int rm = NORMAL): tv_mode(tm) , remote_mode(NORMAL){}
    bool volup(Tv & t){ return t.volup();}
    bool voldown(Tv & t){ return t.voldown();}
    void onoff(Tv & t) {t.onoff(); }
    void chanup(Tv & t){t.chanup();}
    void chandown(Tv & t){t.chandown();}
    void set_chan(Tv & t , int c){t.channel = c;}
    void set_tv_mode(Tv & t){t.set_tv_mode();}
    void set_remote_mode(){remote_mode = (remote_mode == NORMAL) ? INTERACTIVE : NORMAL;}
    void set_input(Tv & t){t.set_input();}
    void show_remote_mode() const;
};

inline void Tv::set_remote_mode(Remote & r){
    if(ison()){
        r.set_remote_mode();
    }
}

#endif