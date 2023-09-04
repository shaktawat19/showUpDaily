/////////////////////////// set: contains only unique value
//        Object constructr

let arr = [1, 2, 3, 4, 2, 3];
let obj = new Set(arr);
console.log(typeof(obj));
console.log(obj);

//////////////////////////// map: key-value
let map = new Map([["name","Harsh"], ["age", 24]]);
console.log(map);
map.set('name', 'jai'); // existing value overriden
map.set('b', 'harshvardhan'); // new pair added
console.log(map);
for(let [key, value] of map)
     console.log(`${key} and ${value}`);

/////////////////////////////////// Weakset: can only store obj, but can iterate.
let weakSet = new WeakSet();
// weakSet.add(1); // invalid
let obj1 = { "1": "hey" }
weakSet.add(obj1);
console.log(weakSet);

/////////////////////////////////// WeakMap : only store obj, cant iterate.
let weakMap = new WeakMap();
let obj2 = { }
weakMap.set(obj2, "something");
console.log(weakMap);

