#ifndef LIQUIDCRYSTAL_MOCK_H
#define LIQUIDCRYSTAL_MOCK_H

class LiquidCrystal {
public:
    LiquidCrystal(int,int,int,int,int,int) {}
    void begin(int, int) {}
    void clear() {}
    void setCursor(int, int) {}
    void print(const char*) {}
    template <typename T>
    void print(T) {}
};

#endif // LIQUIDCRYSTAL_MOCK_H
