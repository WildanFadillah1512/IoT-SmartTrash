const firebaseConfig = {
  apiKey: "AIzaSyDLBGVqv516Ekrmkppx5qsVIuszkUMMEdE",
  authDomain: "tempatsampahpintar-349ea.firebaseapp.com",
  databaseURL: "https://tempatsampahpintar-349ea-default-rtdb.firebaseio.com",
  projectId: "tempatsampahpintar-349ea",
  storageBucket: "tempatsampahpintar-349ea.appspot.com",
  messagingSenderId: "627086025169",
  appId: "1:627086025169:web:4230fad7b873c9df0800f0",
  measurementId: "G-D7C04MTCT4"
};

firebase.initializeApp(firebaseConfig);

const dataRef = firebase.database().ref('/');
dataRef.on('value', (snapshot) => {
  const data = snapshot.val();
  if (data) {
    // Jarak sensor
    document.getElementById('jarakSensor').innerText = `${parseFloat(data.distance_full).toFixed(2)} cm`;

    // Jarak buka tutup
    document.getElementById('jarakTutup').innerText = `${parseFloat(data.distance_open).toFixed(2)} cm`;

    // Persen penuh dan progress bar
    const persen = parseFloat(data.persen_penuh).toFixed(2);
    document.getElementById('persenPenuh').innerText = `${persen} %`;
    document.getElementById('progressBar').style.width = `${persen}%`;

    // Status penuh
    const penuhText = data.is_full ? "Penuh" : "Belum";
    const penuhClass = data.is_full ? "status-red" : "status-green";
    document.getElementById('statusPenuh').innerText = penuhText;
    document.getElementById('statusPenuh').className = penuhClass;
    document.getElementById('statusPenuh2').innerText = penuhText;
    document.getElementById('statusPenuh2').className = penuhClass;

    // Status tutup
    const tutupText = data.status_tutup === "Tertutup" ? "Tertutup" : "Terbuka";
    const tutupClass = data.status_tutup === "Tertutup" ? "status-green" : "status-red";
    const tutupEl = document.getElementById('statusTutup');
    tutupEl.innerText = tutupText;
    tutupEl.className = tutupClass;
  }
});
