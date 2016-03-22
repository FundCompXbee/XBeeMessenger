/***********************************
 * Student: Aaron Crawfis
 * netID: acrawfis
 * Date: 15 March 2016
 * Class: CSE 20212 Final Project
 * File: Packet.cpp
 ************************************/

#include "Packet.h"

Packet::Packet()
{
    
}

void Packet::setJSONstr(string JSON)
{
    JSONstr = JSON;
}

void Packet::setDestination(int dest)
{
    destination = dest;
}

void Packet::setSource(int src)
{
    source = src;
}