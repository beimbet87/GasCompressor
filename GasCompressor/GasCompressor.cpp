#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>

struct GasComponents {
    double methane          = 91.828; 
    double ethane           = 3.049; 
    double propane          = 0.680;      
    double isobutane        = 0.076;
    double normbutane       = 0.130;
    double isopentane       = 0.036;
    double normpentane      = 0.031;
    double hexane           = 0.060;
    double nitrogen         = 3.884;
    double carbon_dioxide   = 0.211;
    double oxygen           = 0.014;

    double summ() {
        return methane + ethane + propane + isobutane + normbutane + isopentane + 
               normpentane + hexane + nitrogen + carbon_dioxide + oxygen;
    }

    double molecularMass() {
        return (methane * 16.04 + ethane * 30.07 + propane * 44.09 + isobutane * 58.12 + normbutane * 58.12 + 
            isopentane * 72.14 + normpentane * 72.14 + hexane * 86.17 + nitrogen * 28.016 + carbon_dioxide * 44.01 + oxygen * 32.00) / 100.0;
    }
};

struct Pressure {
    double in = 32.30;
    double out = 36.40;

    double compressionRatio() {
        return out / in;
    }
};

int main()
{
    // Характериста турбины ГТ-700-5 ------------------------------------

    GasComponents components;
    Pressure pressure;

    double Tn = 15.0; // температура газа на входе нагнетателя [Tn]pr [K]
    double Tv = 3.0; // температура газа на входе нагнетателя [Tn]pr [K]
    double R_PR; // приведенная газовая постаянная Rpr [(нм)/(кг К)] или [Дж/(кг К)]
    double z = 0.87; // приведенный коэффицент сжимаемости в условиях всасывания
    double Q_NO = 1515.0; // номинальный объемный расход газа на входе нагнетателя [м3/мин] или [м3/сек]
    double Q_PR; // приведенный объемный расход газа на входе нагнетателя [м3/мин] или [м3/сек]
    double roC; // плотность газа при стандартных условиях [кг/м3]
    double ro; // плотность газа при рабочих условиях [кг/м3]
    double n = 5000.0; // частота вращения ротора ТВД [об/мин]
    double nn = 5500.0; // частота вращения ротора ТНД [об/мин]
    double ns; // относительные обороты
    double nsPr; // приведенная частота вращения 
    double eps; // степень зжатия газа
    double m; // показатель политропического процесса сжатия 
    double k; // показатель адиабаты
    double kpdPol; // политропический КПД
    double Ni; // внутреняя мощность
    
    ns = n / nn;
    Q_PR = Q_NO / ns;
    eps = pressure.compressionRatio();

    m = log(eps) / (log(eps) - log(Tv / Tn));

    std::cout << "Компонентный состав газа: " << components.summ()  << " %" << std::endl;
    std::cout << "Молекулярная масса газа: " << components.molecularMass()  << " кг/моль" << std::endl;
    std::cout << "Давление на входе: " << pressure.in  << " кг/см2" << std::endl;
    std::cout << "Давление на выходе: " << pressure.out  << " кг/см2" << std::endl;
    
    std::cout << "Степень сжатия: " << eps  << " " << std::endl;
    
    std::cout << "Показатель политропического процесса сжатия: " << m  << " " << std::endl;

    std::cout << "Объемный приведенный расход: " << Q_PR << std::endl;
    std::cout << "Относительные обороты: " << ns << std::endl;

    return 0;
}

double celsiusToFahrenheit(double temperature) {
    return (temperature * 9.0) / 5.0 + 32;
}