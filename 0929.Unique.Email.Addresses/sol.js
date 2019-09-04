/**
 * @param {string[]} emails
 * @return {number}
 */

var emails = ["testemail@leetcode.com","testemail1@leetcode.com","testemail+david@lee.tcode.com"];

var strConvert = function(email) {
    let atIndex = email.indexOf('@');
    let lastPart = email.substr(atIndex, email.length);

    let plusIndex = email.indexOf('+');
    
    let firstPart;
    if (plusIndex === -1) {
        firstPart = email.substr(0, atIndex);
    }
    else {
        firstPart = email.substr(0, plusIndex);
    }
    firstPart = firstPart.replace(/\./g,'');

    return firstPart + lastPart;
}

var numUniqueEmails = function(emails) {
    let mySet = new Set();
    for (let i = 0; i < emails.length; ++i) {
        let email = emails[i];
        email = strConvert(email);
        mySet.add(email);
    }
    return mySet.size;
};

var num = numUniqueEmails(emails);

console.log('num', num);