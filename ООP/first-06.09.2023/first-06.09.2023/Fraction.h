#pragma once

class Fraction
{
public:
    Fraction();
    Fraction(const int numerator, const int denominator);
    ~Fraction() = default;

    int getNumerator();
    int getDenominator();

    void setNumerator(int value);
    void setDenominator(int value);
    
    void print() const;
    
    Fraction sum(Fraction b); // пример: c = a.sum(b)
    Fraction sub(Fraction b);
    Fraction mul(Fraction b);
    Fraction div(Fraction b);
    
    void reduce();
    
private:
  int m_numerator = 0; // Вторая очередь инициализации выполняется только при пропущенной первойэг
  int m_denominator = 1; 
};