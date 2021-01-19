#ifndef STRINGFUNCTIONS_H_INCLUDED
#define STRINGFUNCTIONS_H_INCLUDED

int numberOfCharactersInString(char *str, char searchCharacter);
int removeNonAlphaCharacters(char *source);
int lengthOfString(char *source);
int strConcat(char *str1, char *str2);
int strCopy(char *source, char *destination);
int substring(char *source, int from, int n, char *target);

#endif