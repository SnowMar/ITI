import { categories } from './data.js';

const categoryNames = Object.keys(categories);
const chosenCategory = categoryNames[Math.floor(Math.random() * categoryNames.length)];
const words = categories[chosenCategory];
const chosenWord = words[Math.floor(Math.random() * words.length)];
const hint = chosenWord.hint;


const cat = document.getElementById("category");
cat.textContent = `Category: ${chosenCategory}`;
const wordContainer = document.getElementById("word");
const lettersContainer = document.getElementById("letters");
const messageContainer = document.getElementById("message");
const timerContainer = document.getElementById("timer");
const livesContainer = document.getElementById("lives");



let revealedWord = Array(chosenWord.name.length).fill("_");
let attempts = 6;
let timeLeft = 60;

function renderWord() {
    wordContainer.textContent = revealedWord.join(" ");
}

function createLetterButtons() {
    const alphabet = "abcdefghijklmnopqrstuvwxyz";
    alphabet.split("").forEach(letter => {
        const button = document.createElement("div");
        button.className = "letter";
        button.textContent = letter;
        button.addEventListener("click", () => handleLetterClick(letter, button));
        lettersContainer.appendChild(button);
    });
}

function renderLives() {
    livesContainer.innerHTML = "";
    for (let i = 0; i < attempts; i++) {
        const heart = document.createElement("span");
        heart.textContent = "❤"; 
        heart.style.color = "red";
        heart.style.margin = "0 5px";
        livesContainer.appendChild(heart);
    }
}


function handleLetterClick(letter, button) {
    button.classList.add("disabled");
    button.removeEventListener("click", handleLetterClick);

    if (chosenWord.name.includes(letter)) {
        chosenWord.name.split("").forEach((char, index) => {
            if (char === letter) {
                revealedWord[index] = letter;
            }
        });
        renderWord();
        checkWin();
        timeLeft = 60;
    } else {
        attempts--;
        renderLives();
        timeLeft = 60;
        if (attempts === 0) {
            endGame(false);
        }
    }
}

function checkWin() {
    if (!revealedWord.includes("_")) {
        endGame(true);
    }
}

function endGame(win) {
    disableAllButtons();
    if (win) {
        messageContainer.textContent = "Congratulations! You guessed the word!";
    } else {
        messageContainer.textContent = `Game Over! The word was: ${chosenWord.name}`;
    }
    clearInterval(timerInterval);
}

function disableAllButtons() {
    const buttons = document.querySelectorAll(".letter");
    buttons.forEach(button => button.classList.add("disabled"));
}

function startTimer() {
    timerInterval = setInterval(() => {
        timeLeft--;
        timerContainer.textContent = `Time Left: ${timeLeft} seconds`;
        if (timeLeft === 0) {
            endGame(false);
        }
    }, 1000);
}

document.getElementById("restart").onclick = function() {
    location.reload();
};

document.getElementById("hintBtn").onclick = function() {
    const hintContainer = document.getElementById("hint");
    hintContainer.textContent = `Hint: ${hint}`;
};

renderWord();
createLetterButtons();
renderLives();
startTimer();
