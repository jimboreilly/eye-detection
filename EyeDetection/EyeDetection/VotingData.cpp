#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "VotingData.h"

void VotingData::init(int h, int w, int r) {
    //set properties
    height = h;
    width = w;
    range = r;
    //allocate
    data = new int**[height]();
    unsigned int i = 0, j = 0, k = 0;
    for (i = 0; i<height; ++i) {
        data[i] = new int*[width]();
        for (j = 0; j<width; ++j) {
            data[i][j] = new int[range]();
        }
    }
}

void VotingData::del() {
    unsigned int i = 0, j = 0;
    for (i = 0; i < height; ++i) {
        for (j = 0; j < width; ++j) {
            delete[] data[i][j];
        }
        delete[] data[i];
    }
    delete[] data;
}

void VotingData::cpy(const VotingData & v) {
    //  areIndecesValid(v.getHeight(),v.getWidth(),v.getRange());
    unsigned int i = 0, j = 0, k = 0;
    for (i = 0; i<v.height; i++)
        for (j = 0; j<v.width; j++)
            for (k = 0; k<v.range; k++)
                data[i][j][k] = v.data[i][j][k];
}

void VotingData::areIndecesValid(int h, int w, int r) {
    if (h<0 || h >= height) {
        std::cerr << "height out of range\n";
        exit(EXIT_FAILURE);
    }
    if (w<0 || w >= width) {
        std::cerr << "width out of range\n";
        exit(EXIT_FAILURE);
    }
    if (r<0 || r >= range) {
        std::cerr << "range out of range\n";
        exit(EXIT_FAILURE);
    }
}

VotingData::VotingData(int h, int w, int r) { init(h, w, r); }

VotingData::~VotingData() { del(); }

VotingData::VotingData(const VotingData & v) {
    init(v.height, v.width, v.range);
    // copy contents of v.data to this.data
    cpy(v);
}

VotingData & VotingData::operator=(const VotingData & v) {
    if (this == &v) return *this;  //checks to make sure you didn't call v=v
    del();
    init(v.height, v.width, v.range);
    cpy(v);
    return *this;
}

int VotingData::getHeight() {
    return height;
}

int VotingData::getWidth() {
    return width;
}

int VotingData::getRange() {
    return range;
}

int VotingData::getVal(int i, int j, int k) {
    areIndecesValid(i, j, k);
    return (data[i][j][k]);
}

void VotingData::setVal(int i, int j, int k, int val) {
    areIndecesValid(i, j, k);
    data[i][j][k] = val;
}
