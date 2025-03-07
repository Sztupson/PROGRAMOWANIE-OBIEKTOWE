document.addEventListener('DOMContentLoaded', () => {
    const dogList = document.getElementById('dog-list');
    const addDogForm = document.getElementById('add-dog-form');

    const dogs = JSON.parse(localStorage.getItem('dogs')) || [];

    // Funkcja przeliczająca wiek psa na lata ludzkie
    function calculateHumanAge(age) {
        if (age <= 1) {
            return age * 15;  // Pierwszy rok życia psa to 15 lat ludzkich
        } else if (age === 2) {
            return 15 + 9;  // Drugi rok życia to 9 lat ludzkich
        } else {
            return 15 + 9 + (age - 2) * 5;  // Każdy kolejny rok to 5 lat ludzkich
        }
    }

    function renderDogs() {
        dogList.innerHTML = ''; // Zresetuj listę przed jej ponownym renderowaniem
        dogs.forEach((dog, index) => {
            const dogCard = document.createElement('div');
            dogCard.className = 'dog-card';

            // Przeliczenie wieku psa na lata ludzkie
            const humanAge = calculateHumanAge(dog.age);

            dogCard.innerHTML = `
                <img src="${dog.image}" alt="Zdjęcie ${dog.name}" class="dog-image">
                <h3>${dog.name}</h3>
                <p>Rasa: ${dog.breed}</p>
                <p>Wiek: ${dog.age} lat (${humanAge} lat ludzkich)</p>
                <div class="description">${dog.description}</div>
                <button onclick="toggleDescription(${index})">Pokaż opis</button>
                <button onclick="removeDog(${index})">Usuń</button>
            `;

            dogList.appendChild(dogCard);
        });
    }

    function saveDogs() {
        localStorage.setItem('dogs', JSON.stringify(dogs));
    }

    function addDog(event) {
        event.preventDefault();

        const newDog = {
            name: addDogForm.name.value,
            breed: addDogForm.breed.value,
            age: parseInt(addDogForm.age.value), // Upewnij się, że wiek jest liczbą
            image: addDogForm.image.value,
            description: addDogForm.description.value,
        };

        dogs.push(newDog);
        saveDogs();
        renderDogs();
        addDogForm.reset();
    }

    window.toggleDescription = function(index) {
        const descriptions = document.querySelectorAll('.description');
        const buttons = document.querySelectorAll('.dog-card button:nth-child(5)');

        if (descriptions[index].style.display === 'block') {
            descriptions[index].style.display = 'none';
            buttons[index].innerText = 'Pokaż opis';
        } else {
            descriptions[index].style.display = 'block';
            buttons[index].innerText = 'Ukryj opis';
        }
    };

    window.removeDog = function(index) {
        dogs.splice(index, 1);
        saveDogs();
        renderDogs();
    };

    addDogForm.addEventListener('submit', addDog);

    renderDogs();
});
