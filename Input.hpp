#ifndef INPUT_HPP
#define INPUT_HPP

class Input {

    public:
        // Enter numeric characters. Throw: DigitsOutOfBoundsException
        static int unsignedIntegerNumber(short minimumDigits, short maximumDigits);
        // Enter numeric and '.' character. Throw: DigitsOutOfBoundsException
        static double unsignedRealNumber(short minimumDigits, short maximumDigits);
        // Enter numeric and '-' characters. Throw: DigitsOutOfBoundsException
        static int integerNumber(short minimumDigits, short maximumDigits);
        // Enter numeric, '.' and '-' characters. Throw: DigitsOutOfBoundsException
        static double realNumber(short minimumDigits, short maximumDigits);
        // Enter alphabetics characters
        static char *word(short minimumCharacters, short maximumCharacters);
        // Enter numericc characters. Util for numbers greather or equals than ten digits
        static char *digits(short minimumDigits, short maximumDigits);
        // Enter alphabetics characters and also space key
        static char *alphabetic(short minimumLetters, short maximumLetters);
        // Enter alphabetics and numeric characters and also space key
        static char *alphanumeric(short minimumCharacters, short maximumCharacters);
};

#endif