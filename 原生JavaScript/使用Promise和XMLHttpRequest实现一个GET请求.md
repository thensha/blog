```js
function getUrl(url) {
  return new Promise(function(succ, failure) {
    let req = new XMLHttpRequest()

    req.open('GET', url, true)

    req.addEventListener('load', () => {
      if (req.status < 400) {
        succ(req.responseText)
      } else {
        failure(new Error('Request failded: ', req.statusText))
      }
    })

    req.addEventListener('error', () => {
      failure(new Error('Network Error'))
    })

    req.send(null)
  })
}

getUrl('')
  .then(res => {
    console.log('dataResponsed: ', res)
  })
  .catch(err => {
    console.log('RequestFailed: ', err)
  })

```
