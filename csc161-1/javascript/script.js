var MIN_NAME_LENGTH = 2;
var MIN_PASSWORD_LENGTH = 8;
var MOBILE_DIGITS = 10;
var MIN_AGE = 18;
var MAX_AGE = 100;
var MIN_MESSAGE_LENGTH = 10;
var AT_CODE = 64;

function setFieldState(input, errorEl, message) {
  errorEl.textContent = message;
  input.classList.remove("invalid", "valid");

  if (message) {
    input.classList.add("invalid");
  } else if (input.value.trim().length > 0) {
    input.classList.add("valid");
  }
}

function setStatus(statusEl, ok, text) {
  statusEl.className = text ? "form-status " + (ok ? "success" : "error") : "form-status";
  statusEl.textContent = text;
}

function validateName(name) {
  var trimmed = name.trim();
  var nameLength = trimmed.length;
  var shortBy = MIN_NAME_LENGTH - nameLength;

  if (shortBy > 0) {
    return "Name must be at least " + MIN_NAME_LENGTH + " characters.";
  }

  var letterCount = 0;
  for (var i = 0; i < nameLength; i++) {
    var code = trimmed.charCodeAt(i);
    var isLetter = (code >= 65 && code <= 90) || (code >= 97 && code <= 122);
    var isSpace = code === 32;

    if (isLetter) {
      letterCount++;
    } else if (!isSpace) {
      return "Name may contain only letters and spaces.";
    }
  }

  if (letterCount < MIN_NAME_LENGTH) {
    return "Name must include at least two letters.";
  }

  return "";
}

function validateEmail(email) {
  var trimmed = email.trim();
  var emailLength = trimmed.length;
  var atIndex = trimmed.indexOf("@");
  var dotIndex = trimmed.lastIndexOf(".");
  var atCount = 0;

  if (emailLength === 0) {
    return "Email is required.";
  }

  for (var i = 0; i < emailLength; i++) {
    if (trimmed.charCodeAt(i) === AT_CODE) {
      atCount++;
    }
  }

  var localLength = atIndex;
  var domainLength = emailLength - (atIndex + 1);
  var tldLength = emailLength - (dotIndex + 1);

  if (atCount !== 1 || atIndex < 1) {
    return "Enter a valid email with one @ symbol.";
  }

  if (dotIndex <= atIndex + 1 || tldLength < 2) {
    return "Email domain must include a dot and a TLD.";
  }

  if (localLength < 1 || domainLength < 3) {
    return "Email is too short to be valid.";
  }

  return "";
}

function validatePassword(password) {
  var passwordLength = password.length;
  var missing = MIN_PASSWORD_LENGTH - passwordLength;
  var digitCount = 0;
  var letterCount = 0;

  if (missing > 0) {
    return "Password needs " + missing + " more character(s). Minimum is " + MIN_PASSWORD_LENGTH + ".";
  }

  for (var i = 0; i < passwordLength; i++) {
    var code = password.charCodeAt(i);
    if (code >= 48 && code <= 57) {
      digitCount++;
    }
    if ((code >= 65 && code <= 90) || (code >= 97 && code <= 122)) {
      letterCount++;
    }
  }

  var strength = letterCount + digitCount;
  if (letterCount < 1 || digitCount < 1 || strength < MIN_PASSWORD_LENGTH) {
    return "Password must mix letters and numbers.";
  }

  return "";
}

function validateConfirmPassword(password, confirmPassword) {
  if (confirmPassword.length === 0) {
    return "Confirm your password.";
  }
  if (password !== confirmPassword) {
    return "Passwords do not match.";
  }
  return "";
}

function validateMobile(mobile) {
  var digitsOnly = "";

  for (var i = 0; i < mobile.length; i++) {
    var ch = mobile.charAt(i);
    var code = mobile.charCodeAt(i);

    if (code >= 48 && code <= 57) {
      digitsOnly += ch;
    } else if (ch !== " " && ch !== "-") {
      return "Mobile number may contain digits only.";
    }
  }

  var digitDiff = digitsOnly.length - MOBILE_DIGITS;
  if (digitDiff !== 0) {
    return "Mobile number must be exactly " + MOBILE_DIGITS + " digits.";
  }

  return "";
}

function validateAge(ageText) {
  var age = Number(ageText);
  var underBy = MIN_AGE - age;
  var overBy = age - MAX_AGE;

  if (ageText.trim().length === 0 || isNaN(age)) {
    return "Age is required.";
  }
  if (underBy > 0) {
    return "You must be at least " + MIN_AGE + " years old.";
  }
  if (overBy > 0) {
    return "Enter an age of " + MAX_AGE + " or below.";
  }

  return "";
}

function validateMessage(message) {
  var missing = MIN_MESSAGE_LENGTH - message.trim().length;
  if (missing > 0) {
    return "Message needs " + missing + " more character(s).";
  }
  return "";
}

function clearFields(fields, statusEl) {
  for (var i = 0; i < fields.length; i++) {
    setFieldState(fields[i].input, fields[i].error, "");
  }
  setStatus(statusEl, true, "");
}

function bindReset(form, statusEl, fields) {
  form.addEventListener("reset", function () {
    setTimeout(function () {
      clearFields(fields, statusEl);
    }, 0);
  });
}

function setupLoginForm() {
  var form = document.getElementById("login-form");
  var emailInput = document.getElementById("login-email");
  var passwordInput = document.getElementById("login-password");
  var emailError = document.getElementById("login-email-error");
  var passwordError = document.getElementById("login-password-error");
  var statusEl = document.getElementById("login-status");
  var fields = [
    { input: emailInput, error: emailError },
    { input: passwordInput, error: passwordError }
  ];

  bindReset(form, statusEl, fields);

  form.addEventListener("submit", function (event) {
    event.preventDefault();

    var emailMsg = validateEmail(emailInput.value);
    var passwordMsg = validatePassword(passwordInput.value);
    var errors = 0;

    setFieldState(emailInput, emailError, emailMsg);
    setFieldState(passwordInput, passwordError, passwordMsg);

    if (emailMsg) errors++;
    if (passwordMsg) errors++;

    if (errors > 0) {
      setStatus(statusEl, false, "Fix " + errors + " field(s) and try again.");
      return;
    }

    setStatus(statusEl, true, "Logged in.");
  });
}

function setupRegisterForm() {
  var form = document.getElementById("register-form");
  var nameInput = document.getElementById("reg-name");
  var emailInput = document.getElementById("reg-email");
  var passwordInput = document.getElementById("reg-password");
  var confirmInput = document.getElementById("reg-confirm");
  var mobileInput = document.getElementById("reg-mobile");
  var ageInput = document.getElementById("reg-age");
  var statusEl = document.getElementById("register-status");
  var fields = [
    { input: nameInput, error: document.getElementById("reg-name-error") },
    { input: emailInput, error: document.getElementById("reg-email-error") },
    { input: passwordInput, error: document.getElementById("reg-password-error") },
    { input: confirmInput, error: document.getElementById("reg-confirm-error") },
    { input: mobileInput, error: document.getElementById("reg-mobile-error") },
    { input: ageInput, error: document.getElementById("reg-age-error") }
  ];

  bindReset(form, statusEl, fields);

  form.addEventListener("submit", function (event) {
    event.preventDefault();

    var password = passwordInput.value;
    var messages = [
      validateName(nameInput.value),
      validateEmail(emailInput.value),
      validatePassword(password),
      validateConfirmPassword(password, confirmInput.value),
      validateMobile(mobileInput.value),
      validateAge(ageInput.value)
    ];
    var errors = 0;

    for (var i = 0; i < fields.length; i++) {
      setFieldState(fields[i].input, fields[i].error, messages[i]);
      if (messages[i]) errors++;
    }

    if (errors > 0) {
      setStatus(statusEl, false, errors + " field(s) need fixing.");
      return;
    }

    setStatus(statusEl, true, "Account created.");
  });
}

function setupContactForm() {
  var form = document.getElementById("contact-form");
  var nameInput = document.getElementById("contact-name");
  var emailInput = document.getElementById("contact-email");
  var mobileInput = document.getElementById("contact-mobile");
  var messageInput = document.getElementById("contact-message");
  var statusEl = document.getElementById("contact-status");
  var fields = [
    { input: nameInput, error: document.getElementById("contact-name-error") },
    { input: emailInput, error: document.getElementById("contact-email-error") },
    { input: mobileInput, error: document.getElementById("contact-mobile-error") },
    { input: messageInput, error: document.getElementById("contact-message-error") }
  ];

  bindReset(form, statusEl, fields);

  form.addEventListener("submit", function (event) {
    event.preventDefault();

    var messages = [
      validateName(nameInput.value),
      validateEmail(emailInput.value),
      validateMobile(mobileInput.value),
      validateMessage(messageInput.value)
    ];
    var errors = 0;

    for (var i = 0; i < fields.length; i++) {
      setFieldState(fields[i].input, fields[i].error, messages[i]);
      if (messages[i]) errors++;
    }

    if (errors > 0) {
      setStatus(statusEl, false, errors + " field(s) need fixing.");
      return;
    }

    setStatus(statusEl, true, "Message sent.");
  });
}

setupLoginForm();
setupRegisterForm();
setupContactForm();
