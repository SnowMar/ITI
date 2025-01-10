const words = ["javascript", "hangman", "programming", "html", "coding"];
const chosenWord = words[Math.floor(Math.random() * words.length)];
const wordContainer = document.getElementById("word");
const lettersContainer = document.getElementById("letters");
const messageContainer = document.getElementById("message");

let revealedWord = Array(chosenWord.length).fill("_");
let attempts = 6;

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

function handleLetterClick(letter, button) {
    button.classList.add("disabled");
    button.removeEventListener("click", handleLetterClick);

    if (chosenWord.includes(letter)) {
        chosenWord.split("").forEach((char, index) => {
            if (char === letter) {
                revealedWord[index] = letter;
            }
        });
        renderWord();
        checkWin();
    } else {
        attempts--;
        if (attempts === 0) {
            messageContainer.textContent = `Game Over! The word was: ${chosenWord}`;
            disableAllButtons();
        }
    }
}

function checkWin() {
    if (!revealedWord.includes("_")) {
        messageContainer.textContent = "Congratulations! You guessed the word!";
        disableAllButtons();
    }
}

function disableAllButtons() {
    const buttons = document.querySelectorAll(".letter");
    buttons.forEach(button => button.classList.add("disabled"));
}

renderWord();
createLetterButtons();
