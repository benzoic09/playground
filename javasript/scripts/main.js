const myHeading = document.querySelector("h1");
myHeading.textContent = "Hello world!";

const button_A = document.querySelector("#button_A");
const heading_A = document.querySelector("#heading_A");

button_A.onclick = () => {
  const name = prompt("What is your name?");
  alert(`Hello ${name}, nice to see you!`);
  heading_A.textContent = `Welcome ${name}`;
}; 