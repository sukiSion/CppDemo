#ifndef DMA_H_
#define DMA_H_

class abcDMA{
    private:
    char * label;
    int rating;
    public:
    abcDMA(const char * l = "null" , int r = 0);
    abcDMA(const abcDMA & rs);
    virtual ~abcDMA();
    virtual abcDMA & operator=(const abcDMA & rs);
    virtual void View() const = 0;
};

class baseDMA: public abcDMA{
    public:
    baseDMA(const char * l = "null" , int r = 0);
    baseDMA(const baseDMA & rs);
    void View() const;
};

class lacksDMA: public abcDMA{
    private:
    static const int COL_LEN = 40;
    char color[COL_LEN];
    public:
    lacksDMA(const char * s = "none" , const char * l = "null" , int r = 0);
    lacksDMA(const char * s , const abcDMA & rs);
    void View() const;
};

class hasDMA: public abcDMA{
    private:
    char * style;
    public:
    hasDMA(const char * s = "none" , const char * l = "null" , int r = 0);
    hasDMA(const char * s , const abcDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA & operator=(const hasDMA & hs);
    void View() const;
};

#endif