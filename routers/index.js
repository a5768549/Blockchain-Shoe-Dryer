const { Router } = require('express')
const ControlRouter = require('./ControlRouter');
/** 根路由 */
const RouterRoot = Router();
RouterRoot.use('/control', ControlRouter);
module.exports = RouterRoot;