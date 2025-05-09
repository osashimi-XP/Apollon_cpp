// ******************************************************
// Project Name    : ForRocket
// File Name       : sequence_clock.cpp
// Creation Date   : 2019/11/08
//
// Copyright (c) 2019 Susumu Tanaka. All rights reserved.
// Copyright (c) 2025 Yo Tobetto. All rights reserved.
// ******************************************************

#include "sequence_clock.hpp"

#include <cmath>

#ifdef DEBUG
#include <iostream>
#endif

void forrocket::SequenceClock::UpdateJulianDate() {
    DateTime UTC_date = UTC_date_init + countup_time;
    julian_data = UTC2JulianDate(UTC_date);
    modified_julian_date = JulianDate2ModifiedJulianDate(julian_data);
    greenwich_sidereal_time = JulianDate2GreenwichSiderealTime(julian_data);
};


forrocket::SequenceClock::SequenceClock() {
    UTC_date_init = DateTime();
    countup_time = 0.0;
    UpdateJulianDate();
};

forrocket::SequenceClock::SequenceClock(DateTime UTC_init) {
    UTC_date_init = UTC_init;
    countup_time = 0.0;
    countup_time_ref = 0.0;
    UpdateJulianDate();
};

forrocket::SequenceClock::SequenceClock(DateTime UTC_init, double countup_time_init) {
    UTC_date_init = UTC_init;
    countup_time = 0.0;
    countup_time_ref = countup_time_init;
    UpdateJulianDate();
};

void forrocket::SequenceClock::SyncSolverTime(const double t) {
    countup_time = t - countup_time_ref;
    UpdateJulianDate();
};


double forrocket::SequenceClock::UTC2JulianDate(DateTime& UTC) {
    // return 367 * UTC.year - static_cast<int>(7 * (UTC.year + static_cast<int>((UTC.month + 9) / 12)) / 4) + static_cast<int>(275 * UTC.month / 9)
    //             + UTC.day + 1721013.5 + ((UTC.sec / 60.0 + UTC.min) / 60.0 + UTC.hour) / 24.0;
    return 367 * UTC.year - static_cast<int>(7 * (UTC.year + static_cast<int>((UTC.month + 9) / 12)) / 4) + static_cast<int>(275 * UTC.month / 9)
                + UTC.day + 1721013.5 + ((UTC.sec / 60.0 + UTC.min) / 60.0 + UTC.hour) / 24.0;
};


double forrocket::SequenceClock::JulianDate2GreenwichSiderealTime(const double julian) {
    double julian_century = (julian - 2451545.0) / 36525.0;
    double greenwich_sidereal = 67310.54841 + (876600.0 * 3600.0 + 8640184.812866) * julian_century + 0.093104 * std::pow(julian_century, 2) - 6.2e-6 * std::pow(julian_century, 3);
    // double green_sidereal_deg = greenwich_sidereal_time / 240.0;
    greenwich_sidereal = greenwich_sidereal * std::fmod((2.0 * 3.14159265) / 86400.0, (2.0 * 3.14159265));
    return greenwich_sidereal;
};


double forrocket::SequenceClock::UTC2GreenwichSiderealTime(DateTime& UTC) {
    double julian = UTC2JulianDate(UTC);
    return JulianDate2GreenwichSiderealTime(julian);
};


double forrocket::SequenceClock::JulianDate2ModifiedJulianDate(const double julian) {
    return julian - 2400000.5;
};


forrocket::DateTime forrocket::SequenceClock::ModifiedJulianDate2UTC(const double modified_julian) {
    double a = static_cast<int>(modified_julian) + 2400001.0;
    double q = modified_julian - static_cast<int>(modified_julian);
    double b = static_cast<int>((a - 1867216.25) / 36524.25);
    double c = a + b - static_cast<int>(0.25 * b) + 1525;
    double d = static_cast<int>((c - 121.1) / 365.25);
    double e = static_cast<int>(365.25 * d);
    double f = static_cast<int>((c - e) / 50.6001);

    unsigned int day = c - e - static_cast<unsigned int>(30.6001 * f);
    unsigned int month = f - 1 - 12 * static_cast<unsigned int>(f / 14);
    unsigned int year = d - 4715 - static_cast<unsigned int>((7 + month) / 10);
    unsigned int hour = static_cast<unsigned int>(24 * q);
    unsigned int min = 60 * (24 * q - hour);
    unsigned int sec = 60 * (min) - static_cast<unsigned int>(min);
    return DateTime(year, month, day, hour, min, sec);
};










