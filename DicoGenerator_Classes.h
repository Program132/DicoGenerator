#pragma once

char returnGoodLetter(char l) {
    switch (l) {
        case 'a':
            return '@';
        case 'b':
            return '8';
        case 'c':
            return '(';
        case 'e':
            return '3';
        case 'g':
            return '9';
        case 'h':
            return '#';
        case 'i':
            return '!';
        case 'l':
            return '1';
        case 'o':
            return '0';
        case 's':
            return '5';
        case 't':
            return '7';
        case 'x':
            return '%';
        default:
            return l;
    }
}

char returnGoodLetter_second(char l) {
    switch (l) {
        case 'a':
            return '@';
        case 'b':
            return '8';
        case 'c':
            return '<';
        case 'e':
            return '3';
        case 'g':
            return '9';
        case 'h':
            return '4';
        case 'i':
            return '1';
        case 'l':
            return '|';
        case 's':
            return '$';
        case 'x':
            return '*';
        case 'o':
            return '0';
        case 't':
            return '7';
        default:
            return l;
    }
}