#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

/* This will be based on the HRC tool hex files */

enum MAP_TYPE {
                MAP_UNKNOWN = 0,
                MAP_CBR600RR07 = 10,
                MAP_CBR1000RR08 = 11
              };

#define HEX_EOF ":00000001FF"
#define HEX_START ":"
#define CBR600RR07_SIGN_HEX "30374342523630304B4541364B4F"
#define CBR600RR07_SIGN_STRING "07CBR600KEA6KO"

struct cbr600rr07_map_t {

    /* All RPM values are divided by 100 to fit in 8 bits */
    char ign1[4*16];     /* Ignition table */
    char dummy1[16];    /* Unknown - zeros */
    char ign2[7*16];     /* Ignition table */
    char fuel1[7*16];    /* Fuel table */
    char dummy2[16];    /* Unknown - zeros */
    char fuel2[4*16];    /* Fuel table */
    char rpm_row[16];   /* RPM row values */
    char tps_row[11];   /* TPS row values */
    char dummy3;        /* Unknown */
    char staging[16];   /* Staging table */
    char pit_limiter;   /* Pit limiter value */
    char dummy4;        /* Unknown - zeros */
    char shift_light;   /* Shift light value */
    char dummy5;        /* Unknown - zeros */
    char idle;          /* Idle value */
    char dummy6;        /* Unknown - zeros */
    char signature[14]; /* "07CBR600KEA6KO" */
};


#endif // DATASTRUCTURES_H
