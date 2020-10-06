const express = require('express')
const fetch = require("node-fetch")

const app = express()

app.use(express.json())
app.use(express.urlencoded({extended: true}))

app.set('view engine', 'hbs')

app.get('/', (req, res) => {
    res.render('index')
})

app.get('/:id', (req, res) => {

    let name = req.params.id;
    console.log(name)
    fetch(`http://api.openweathermap.org/data/2.5/weather?q=${name}&APPID=381463ce364fe81d1108d0992b6b869f`)
    .then(res => res.json())
    .then((data) => {
        console.log(data)
        res.send(data)
    })
})

app.listen(4343, () => {
    console.log("Server started at!")
})