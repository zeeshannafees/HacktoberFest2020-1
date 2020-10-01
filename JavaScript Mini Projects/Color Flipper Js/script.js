const colorcode = document.getElementById("colorcode");
const button = document.querySelector(".btn");


// Add EventListner to button
button.addEventListener("click", function message(){
    var random = Math.floor(Math.random()*16777215).toString(16);
    // console.log("#" + random);
     document.body.style.backgroundColor = "#"+random;
     colorcode.textContent = "#"+random;

});