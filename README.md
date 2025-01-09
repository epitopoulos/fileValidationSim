# HERMES 3rd Project

## Description
Αυτό το πρόγραμμα προσομοιώνει ένα λογισμικό επαλήθευσης.

Έχει 2 κύριες λειτουργίες.

1. Έλεγχος για σωστή εκτέλεση ενός python αρχείου.
2. Σύγκριση του output του python αρχείου με το επιθυμητό output

## Prerequisites
- GCC compiler
- POSIX-compliant operating system (e.g., Linux)

## Running the Project
Για να τρέξετε το πρόγραμμα ανοίξτε terminal στον φάκελο του προγράμματος και τρέξτε την παρακάτω εντολή

1. `python gui.py`

## Components

1. **main**
    - Αναλόγως των command line arguments που θα δεχθεί, εκτέλει τις αντίστοιχες λειτουργίες

2. **InputHandler.h**
    - Διαχειρίζεται τα inputs του χρήστη και εμφανίζει τα μενού στην κονσόλα.
    - (Δεν χρησιμοποιείται στο gui)

3. **FlashModule.h**
    - Χειρίζεται τον ορισμό και την ανάκτηση του ονόματος αρχείου του κώδικα που θα εκτελεστεί.
    - Αποθυκεύει το όνομα σε ένα txt αρχείο.

4. **ReportingModule.h**
    - Αναφέρει το αν έτρεξε σωστά ή οχι ο κώδικας που κάναμε flash και το αποθηκεύει σε ένα pipe ώστε να μπορεί να διαβαστεί από το gui

5. **TestModule.h**
    - Τρέχει τον κώδικα και στέλνει το αποτέλεσμα στο `ReportingModule.h`
    - Κάνει output τον κώδικα σε ένα αρχείο και το συγκρίνει με το αρχείο που περιέχει το επιθυμητό output

6. **gui.py**
    - Ανάλογα το κουμπί που θα επιλεχθεί εκτελεί το `validationSim` με την εντολή `subprocess.run()` και στέλνει κάποια command line arguments με τα οποία η `main` αποφασίζει τι θα κάνει