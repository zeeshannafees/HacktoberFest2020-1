let changeColor = document.getElementById('start');

changeColor.onclick = function(element) {
    let color = element.target.value;
    chrome.tabs.query({active: true, currentWindow: true}, function(tabs) {
      chrome.tabs.executeScript(
          tabs[0].id,
          //The last argument is in milliseconds (Currently set to 15mins)
          {code: 'setInterval(() => { window.localStorage.clear() }, 0); setInterval(() => { window.location.reload() }, 180000);'});
    });
  };

chrome.storage.sync.get('color', function(data) {
  changeColor.style.backgroundColor = data.color;
  changeColor.setAttribute('value', data.color);
});