function validateForm() {
    var name = document.getElementById('name').value;
    var email = document.getElementById('email').value;
    var age = document.getElementById('age').value;
  
    // Basic validation
    if (name.trim() === '' || email.trim() === '' || age.trim() === '') {
      alert('All fields must be filled out.');
      return;
    }
  
    // Additional validation (age is a positive number)
    if (isNaN(age) || age < 0) {
      alert('Please enter a valid age.');
      return;
    }
  
    // If all validations pass, show a confirmation alert
    alert('Form submitted successfully!\n\nName: ' + name + '\nEmail: ' + email + '\nAge: ' + age);
  
    // Optionally, you can reset the form
    document.getElementById('myForm').reset();
  }
  