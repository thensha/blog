# createElement() 和 ReactElement()

> 例: jsx转js(Babel)

```jsx harmony
function Foo () {
  return <div id='root' class='div1' >
    <span>text1</span>
    <span>text2</span>
  </div>
}

Foo()
```

```js
function Foo() {
  return React.createElement('div', {
      id: 'root',
      class: 'div1'
    },
    React.createElement('span', null, 'text1'),
    React.createElement('span', null, 'text2'),
  )
}

Foo()
```

## createElement

> 函数作用: 
1. 筛选保留属性, 构建props对象
2. 判断参数个数, 大于3时将从第三个开始后续属性都加入props.children数组中
3. 判断defaultProps, 如果props中没赋值, 就用默认值
```
class Comp extends React.Component
Comp.defaultProps = {}
```

> 源码实现:

```js

// 参数: 
// 节点类型(原生节点: String; 非原生: class fragment || functional fragment || React fragment(只是一种Symbol: Fragment/StrictMode/Suspense))
// 节点属性({key: value}形式, 需要从中筛选出react保留属性, ref/key/self/source, 其余普通属性放入节点的props对象)
// 从第三个参数开始, 都属于节点内容, 统一放入一个props.children(既可以是标签内容, 也可以是子标签)

function createElement(type, config, children) {
  let propName;

  // Reserved names are extracted
  const props = {};

  let key = null;
  let ref = null;
  let self = null;
  let source = null;

  if (config != null) {
    if (hasValidRef(config)) {
      ref = config.ref;
    }
    if (hasValidKey(config)) {
      key = '' + config.key;
    }

    self = config.__self === undefined ? null : config.__self;
    source = config.__source === undefined ? null : config.__source;
    // Remaining properties are added to a new props object
    for (propName in config) {
      if (
        hasOwnProperty.call(config, propName) &&
        !RESERVED_PROPS.hasOwnProperty(propName)
      ) {
        props[propName] = config[propName];
      }
    }
  }

  // Children can be more than one argument, and those are transferred onto
  // the newly allocated props object.
  const childrenLength = arguments.length - 2;
  if (childrenLength === 1) {
    props.children = children;
  } else if (childrenLength > 1) {
    const childArray = Array(childrenLength);
    for (let i = 0; i < childrenLength; i++) {
      childArray[i] = arguments[i + 2];
    }
    if (__DEV__) {
      if (Object.freeze) {
        Object.freeze(childArray);
      }
    }
    props.children = childArray;
  }

  // Resolve default props
  if (type && type.defaultProps) {
    const defaultProps = type.defaultProps;
    for (propName in defaultProps) {
      if (props[propName] === undefined) {
        props[propName] = defaultProps[propName];
      }
    }
  }

  return ReactElement(
    type,
    key,
    ref,
    self,
    source,
    ReactCurrentOwner.current,
    props,
  );
}
```

## ReactElement

> 作用: 返回一个带有各项属性的节点对象, 重点是$$typeof属性, 代表了此节点的类型
> 如'react.element', 'react.fragment', 'react.provider', 'react.forward_ref'等12种

```jsx harmony
const ReactElement = function(type, key, ref, self, source, owner, props) {
  const element = {
    // This tag allows us to uniquely identify this as a React Element
    $$typeof: REACT_ELEMENT_TYPE,

    // Built-in properties that belong on the element
    type: type,
    key: key,
    ref: ref,
    props: props,

    // Record the component responsible for creating this element.
    _owner: owner,
  };

  return element;
};
```
