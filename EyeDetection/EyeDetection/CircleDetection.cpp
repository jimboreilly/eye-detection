#include "stdafx.h"
#include "CircleDetection.h"
using namespace std;

CircleDetection::CircleDetection(void) {}

CircleDetection::~CircleDetection() {}

void CircleDetection::voting(VotingData & data, int minRad, Image & im) {
    int a = 0, b = 0, d = 0, x = 0, y = 0, r = 0;
    VotingData lookup(data.getHeight(), data.getWidth(), data.getRange());
    VotingData blank(data.getHeight(), data.getWidth(), data.getRange());

    for (y = 0; y<data.getHeight(); y++) {
        for (x = 0; x<data.getWidth(); x++) {
            if (im.getVal(x, y) == 1) {
                for (r = 0; r<data.getRange(); r++) {
                    lookup = blank;
                    for (d = 0; d<MAX_DEG; d++) {
                        a = x - (r + minRad) * cos(d * PI / 180);
                        b = y - (r + minRad) * sin(d * PI / 180);
                        if ((a + r + 1) >= data.getWidth() || (a - r + 1)<0 || (b + r + 1) >= data.getHeight() || (b - r + 1)<0) { continue; }
                        if (a<data.getHeight() && a>0 && b<data.getWidth() && b>0) {
                            if (lookup.getVal(a, b, r) != 0) { continue; }
                            data.setVal(a, b, r, data.getVal(a, b, r) + 1); // increment data entry
                            lookup.setVal(a, b, r, lookup.getVal(a, b, r) + 1);
                        }
                    }
                }
            }
        }
    }
}

Circle CircleDetection::bestCircle(VotingData & v, int minRad) {
    unsigned int i = 0, j = 0, k = 0;
    int bestH = 0, bestW = 0, bestR = 0, bestScore = 0;
    for (i = 0; i<v.getHeight(); i++) {
        for (j = 0; j<v.getWidth(); j++) {
            for (k = 0; k<v.getRange(); k++) {
                if (bestScore < v.getVal(i, j, k)) {
                    bestH = i;
                    bestW = j;
                    bestR = k;
                    bestScore = v.getVal(i, j, k);
                }
            }
        }
    }
    Circle out(bestH, bestW, bestR + minRad);
    return(out);
}

Circle CircleDetection::detectCircle(Image & im, int height, int width, int minRad, int range) {
    cout << "running CircleDetection functionality\n";

    VotingData data(height, width, range);

    voting(data, minRad, im);

    return (bestCircle(data, minRad));
}
