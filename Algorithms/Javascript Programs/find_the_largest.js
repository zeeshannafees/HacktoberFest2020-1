/*
Task

Given a number , Return _The Maximum number _ could be formed from the digits of the number given .
Notes

Only Natural numbers passed to the function , numbers Contain digits [0:9] inclusive !alt !alt

Digit Duplications could occur , So also consider it when forming the Largest !alt

Input >> Output Examples:

maxNumber (213) ==> return (321)

Explanation:

As 321 is _The Maximum number _ could be formed from the digits of the number *213*** .

maxNumber (566797) ==> return (977665)

Explanation:

As 977665 is _The Maximum number _ could be formed from the digits of the number *566797*** .

Note : Digit duplications are considered when forming the largest .
 */

function maxNumber(n) {
    const arr = ("" + n).split("");
    return parseInt(arr.sort((a, b) => b - a).join(""));
}