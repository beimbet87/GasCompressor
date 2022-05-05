/*
    КС-14
    ГПА N6
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>

class Crane {
public:
    double density;
    double pressure;
    double ksi;
    double d;
    double lambda;
    double Re = 18000000.0;
    double A;
    double velocity;

    double a = 190.0;
    double b = 230.0;
    double c = 680.0;

    double weisbach() {

    }

    double area() {
        return 0.5 * (a + b) * sqrtf(c * c - powf(((b - a) * (b - a)) / (2.0 * (b - a)), 2.0));
    }

    double getKsi() {
        return getA(10) / Re + getKsiInArea(10);
    }

    double getA(int degree) {
        double currentA;
        switch (degree) {
        case 0:
            currentA = 150.0;
            break;
        case 10:
            currentA = 318.0;
            break;
        case 20:
            currentA = 430.0;
            break;
        case 30:
            currentA = 695.0;
            break;
        case 40:
            currentA = 1680.0;
            break;
        case 45:
            currentA = 4500.0;
            break;
        default:
            currentA = 150;
        }
        return currentA;
    }

    double getKsiInArea(int degree) {
        double currentKsi;
        switch (degree) {
        case 0:
            currentKsi = 1.68;
            break;
        case 10:
            currentKsi = 3.20;
            break;
        case 20:
            currentKsi = 6.80;
            break;
        case 30:
            currentKsi = 18.50;
            break;
        case 40:
            currentKsi = 49.0;
            break;
        case 45:
            currentKsi = 126.0;
            break;
        default:
            currentKsi = 150;
        }
        return currentKsi;
    }

};

class Turbine {
public:
    std::string code;
    std::string place;
    std::string type;
    std::string manufacturer;
    std::string model;
    std::string release_year;
    double resource;
    double capacity;
};

struct Gas {
public:

    void setFraction(double fraction) {
        this->fraction = fraction;
    }

    double getFraction() {
        return this->fraction;
    }

    void setDensity(double density) {
        this->density = density;
    }

    double getDensity() {
        return this->density;
    }

    void setViscosity(double viscosity) {
        this->viscosity = viscosity;
    }

    double getViscosity() {
        return this->viscosity;
    }

    void setMolarMass(double molar_mass) {
        this->molar_mass = molar_mass;
    }

    double getMolarMass() {
        return this->molar_mass;
    }

    void setGasConstant(double gas_constant) {
        this->gas_constant = gas_constant;
    }

    double getGasConstant() {
        return this->gas_constant;
    }

private:
    double density;
    double viscosity;
    double molar_mass;
    double gas_constant;
    double fraction;
};

class GasComponents {
    Gas methane, ethane, propane, isobutane, normbutane, isopentane;
    Gas normpentane, hexane, nitrogen, carbon_dioxide, oxygen;
public:

    GasComponents(double temperature, double pressure) {
        this->temperature = temperature;
        this->pressure = pressure;

        if (temperature == 273.15 && pressure == 0.1013) {
            methane.setDensity(0.717);
            methane.setViscosity(1.020);
            ethane.setDensity(1.356);
            ethane.setViscosity(0.880);
            propane.setDensity(2.010);
            propane.setViscosity(0.770);
            isobutane.setDensity(2.307);
            isobutane.setViscosity(0.690);
            normbutane.setDensity(2.307);
            normbutane.setViscosity(0.690);
            isopentane.setDensity(3.457);
            isopentane.setViscosity(0.636);
            normpentane.setDensity(3.457);
            normpentane.setViscosity(0.636);
            hexane.setDensity(0.717);
            hexane.setViscosity(1.020);
            nitrogen.setDensity(1.251);
            nitrogen.setViscosity(1.710);
            carbon_dioxide.setDensity(1.977);
            carbon_dioxide.setViscosity(1.400);
            oxygen.setDensity(0.717);
            oxygen.setViscosity(1.020);
        }
        else if (temperature == 293.15 && pressure == 0.1013) {
            methane.setDensity(0.669);
            methane.setViscosity(1.102);
            ethane.setDensity(1.264);
            ethane.setViscosity(0.940);
            propane.setDensity(1.872);
            propane.setViscosity(0.820);
            isobutane.setDensity(2.519);
            isobutane.setViscosity(0.760);
            normbutane.setDensity(2.519);
            normbutane.setViscosity(0.760);
            isopentane.setDensity(3.228);
            isopentane.setViscosity(0.632);
            normpentane.setDensity(3.228);
            normpentane.setViscosity(0.632);
            hexane.setDensity(0.717);
            hexane.setViscosity(1.020);
            nitrogen.setDensity(1.165);
            nitrogen.setViscosity(1.840);
            carbon_dioxide.setDensity(1.842);
            carbon_dioxide.setViscosity(1.650);
            oxygen.setDensity(0.717);
            oxygen.setViscosity(1.020);
        }

        methane.setFraction(91.828);
        methane.setMolarMass(16.04);
        methane.setGasConstant(518.57);
        ethane.setFraction(3.0490);
        ethane.setMolarMass(30.07);
        ethane.setGasConstant(276.64);
        propane.setFraction(0.6800);
        propane.setMolarMass(44.09);
        propane.setGasConstant(188.68);
        isobutane.setFraction(0.0760);
        isobutane.setMolarMass(58.12);
        isobutane.setGasConstant(143.08);
        normbutane.setFraction(0.1300);
        normbutane.setMolarMass(58.12);
        normbutane.setGasConstant(143.08);
        isopentane.setFraction(0.0360);
        isopentane.setMolarMass(72.15);
        isopentane.setGasConstant(115.23);
        normpentane.setFraction(0.0310);
        normpentane.setMolarMass(72.15);
        normpentane.setGasConstant(115.23);
        hexane.setFraction(0.0600);
        hexane.setMolarMass(86.17);
        hexane.setGasConstant(518.57);
        nitrogen.setFraction(3.8840);
        nitrogen.setMolarMass(28.02);
        nitrogen.setGasConstant(296.75);
        carbon_dioxide.setFraction(0.2110);
        carbon_dioxide.setMolarMass(44.01);
        carbon_dioxide.setGasConstant(188.97);
        oxygen.setFraction(0.0140);
        oxygen.setMolarMass(32.00);
        oxygen.setGasConstant(259.8);
    }

    double summ() {
        return methane.getFraction() + ethane.getFraction() + propane.getFraction() + isobutane.getFraction() +
            normbutane.getFraction() + isopentane.getFraction() + normpentane.getFraction() + hexane.getFraction() +
            nitrogen.getFraction() + carbon_dioxide.getFraction() + oxygen.getFraction();
    }

    double molecularMass() {
        return (methane.getFraction() * methane.getMolarMass() +
            ethane.getFraction() * ethane.getMolarMass() +
            propane.getFraction() * propane.getMolarMass() +
            isobutane.getFraction() * isobutane.getMolarMass() +
            normbutane.getFraction() * normbutane.getMolarMass() +
            isopentane.getFraction() * isopentane.getMolarMass() +
            normpentane.getFraction() * normpentane.getMolarMass() +
            hexane.getFraction() * hexane.getMolarMass() +
            nitrogen.getFraction() * nitrogen.getMolarMass() +
            carbon_dioxide.getFraction() * carbon_dioxide.getMolarMass() +
            oxygen.getFraction() * oxygen.getMolarMass()) / 100.0;
    }

    double getNormalDensity() {
        return molecularMass() / 22.41;
    }

    double getGasConstant() {
        return universalGasConstant / molecularMass();
    }

private:
    double temperature;
    double pressure;
    double universalGasConstant = 8314.3;
};

class Pressure {
public:
    double in = 30.09;
    double out = 35.09;
    double nominal_in = 45.0;
    double nominal_out = 56.0;

    double critical = nominal_out;
    double reduced = out / critical;

    double compressionRatio() {
        return out / in;
    }
};

class Temperature {
public:
    double in = 7.0 + 273.15;
    double out = 20.0 + 273.15;
    double nominal_in;
    double nominal_out;
    double critical;
    double reduced = 15.0 + 273.15;
};

int main()
{
    // Характериста турбины ГТ-700-5 ------------------------------------

    GasComponents components(293.15, 0.1013);
    Pressure pressure;
    Turbine turbine;
    Temperature temperature;
    double Tn = 15.0; // температура газа на выходе нагнетателя [Tn]pr [K]
    double Tv = 3.0; // температура газа на входе нагнетателя [Tn]pr [K]
    double R_PR; // приведенная газовая постаянная Rpr [(нм)/(кг К)] или [Дж/(кг К)]
    double z_reduced = 0.87; // приведенный коэффицент сжимаемости в условиях всасывания
    double z; // коэффициент сжимаемости газа
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

    double A1, A2;

    A1 = -0.39 + 2.03 / temperature.reduced + 3.16 / powf(temperature.reduced, 2.0) + 1.09 / powf(temperature.reduced, 3.0);
    A2 = 0.0423 - 0.1812 / temperature.reduced + 0.2124 / (temperature.reduced * temperature.reduced);

    z = 1 + A1 * pressure.reduced + A2 * pressure.reduced * pressure.reduced;

    std::cout << "Компонентный состав газа: " << components.summ() << " %" << std::endl;
    std::cout << "Молекулярная масса газа: " << components.molecularMass() << " кг/моль" << std::endl;
    std::cout << "Плотность газа при нормальных условиях: " << components.getNormalDensity() << " м3/кмоль" << std::endl;
    std::cout << "Газовая постоянная природного газа: " << components.getGasConstant() << " Дж/(кг*К)" << std::endl;
    std::cout << "Давление на входе: " << pressure.in << " кг/см2" << std::endl;
    std::cout << "Давление на выходе: " << pressure.out << " кг/см2" << std::endl;

    std::cout << "Коэффициент сжимаемости газа: " << z << std::endl;

    std::cout << "Степень сжатия: " << eps << " " << std::endl;

    std::cout << "Показатель политропического процесса сжатия: " << m << " " << std::endl;

    std::cout << "Объемный приведенный расход: " << Q_PR << std::endl;
    std::cout << "Относительные обороты: " << ns << std::endl;

    Crane crane;

    std::cout << std::endl;
    std::cout << "------- Результаты по крану ------------------------- " << std::endl;

    std::cout << "Площадь отверствия: " << crane.area() << " мм2" << std::endl;
    std::cout << "Коэффициент местного сопротивления: " << crane.getKsi() << std::endl;


    return 0;
}

double celsiusToKelvin(double temperature) {
    return temperature + 273.15;
}

double KelvinToCelsius(double temperature) {
    return temperature - 273.15;
}